#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_SYMBOL_LENGTH 10
#define MAX_SYMBOLS 100
#define MAX_OPCODES 100

struct symbol_entry {
    char label[MAX_SYMBOL_LENGTH];
    int address;
};

struct symbol_table {
    struct symbol_entry entries[MAX_SYMBOLS];
    int count;
};

struct opcode_entry {
    char instruction[MAX_SYMBOL_LENGTH];
    char opcode[MAX_SYMBOL_LENGTH];
    int size;
};

struct opcode_table {
    struct opcode_entry entries[MAX_OPCODES];
    int count;
};

int is_comment(char *line) {
    return line[0] == '.';
}

void insert_symbol(struct symbol_table *symtab, char *label, int address) {
    strcpy(symtab->entries[symtab->count].label, label);
    symtab->entries[symtab->count].address = address;
    symtab->count++;
}

int search_symtab(struct symbol_table *symtab, char *label) {
    for (int i = 0; i < symtab->count; i++) {
        if (strcmp(symtab->entries[i].label, label) == 0) {
            return i;
        }
    }
    return -1;
}

void load_optab(struct opcode_table *optab, const char *filename) {
    FILE *optab_file = fopen(filename, "r");
    if (!optab_file) {
        printf("Error opening OPTAB file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), optab_file) && optab->count < MAX_OPCODES) {
        sscanf(line, "%s %s %d", 
               optab->entries[optab->count].instruction,
               optab->entries[optab->count].opcode,
               &optab->entries[optab->count].size);
        optab->count++;
    }

    fclose(optab_file);
}

int get_instruction_size(struct opcode_table *optab, char *instruction) {
    for (int i = 0; i < optab->count; i++) {
        if (strcmp(optab->entries[i].instruction, instruction) == 0) {
            return optab->entries[i].size;
        }
    }
    return -1;  // Instruction not found
}

int main() {
    FILE *source_file = fopen("source.txt", "r");
    FILE *intermediate_file = fopen("intermediate.txt", "w");
    FILE *symtab_file = fopen("symtab.txt", "w");

    if (!source_file || !intermediate_file || !symtab_file) {
        printf("Error opening files.\n");
        return 1;
    }

    struct opcode_table optab = {0};
    load_optab(&optab, "optab.txt");

    char line[MAX_LINE_LENGTH];
    char label[MAX_SYMBOL_LENGTH], opcode[MAX_SYMBOL_LENGTH], operand[MAX_SYMBOL_LENGTH];
    int locctr = 0, starting_address = 0;
    struct symbol_table symtab = {0};

    if (fgets(line, sizeof(line), source_file)) {
        sscanf(line, "%s %s %s", label, opcode, operand);
        if (strcmp(opcode, "START") == 0) {
            starting_address = atoi(operand);
            locctr = starting_address;
            fprintf(intermediate_file, "%s", line);
        } else {
            locctr = 0;
        }
    }

    while (fgets(line, sizeof(line), source_file)) {
        sscanf(line, "%s %s %s", label, opcode, operand);
        printf("%s %s %s\n", label, opcode, operand);

        if (!is_comment(line)) {
            if (strlen(label) > 0) {
                if (search_symtab(&symtab, label) != -1) {
                    printf("Error: Duplicate symbol %s\n", label);
                } else {
                    insert_symbol(&symtab, label, locctr);
                }
            }

            int instruction_size = get_instruction_size(&optab, opcode);
            if (instruction_size != -1) {
                locctr += instruction_size;
            } else if (strcmp(opcode, "WORD") == 0) {
                locctr += 3;
            } else if (strcmp(opcode, "RESW") == 0) {
                locctr += 3 * atoi(operand);
            } else if (strcmp(opcode, "RESB") == 0) {
                locctr += atoi(operand);
            } else if (strcmp(opcode, "BYTE") == 0) {
                if (operand[0] == 'C') {
                    locctr += strlen(operand) - 3;
                } else if (operand[0] == 'X') {
                    locctr += (strlen(operand) - 3 + 1) / 2;
                }
            } else {
                printf("Error: Invalid opcode %s\n", opcode);
            }

            fprintf(intermediate_file, "%04X %s", locctr, line);
        }

        if (strcmp(opcode, "END") == 0) {
            break;
        }
    }

    fprintf(intermediate_file, "%04X %s", locctr, line);
    int program_length = locctr - starting_address;

    for (int i = 0; i < symtab.count; i++) {
        fprintf(symtab_file, "%s %04X\n", symtab.entries[i].label, symtab.entries[i].address);
    }

    fclose(source_file);
    fclose(intermediate_file);
    fclose(symtab_file);

    printf("Pass 1 completed. Program length: %04X\n", program_length);

    return 0;
}

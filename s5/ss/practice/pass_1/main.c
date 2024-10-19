#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN 100

const char* delim = "^ \n";

FILE *optab_fp;
FILE *src_fp;
FILE *intmd_fp;
FILE *symtab_fp;

struct src_line {
    int addr;
    char* label;
    char* opcode;
    char* operand;
} parsed_src[100];

struct optab {
    char* opcode;
    char* hex; 
} parsed_optab[100];

struct symtab {
    char symbol[10];
    int addr;
} parsed_symtab[100];

int src_len = 0;
int optab_len = 0;
int symtab_len = 0;
int locctr = 0;

void parse_src() {
    char line[LEN];
    int i = 0;

    while (fgets(line, sizeof(line), src_fp)) {
        char* token = strtok(line, delim);
        parsed_src[i].label = (token != NULL)? strdup(token): "";
        token = strtok(NULL, delim);
        parsed_src[i].opcode = (token != NULL)? strdup(token): "";
        token = strtok(NULL, delim);
        parsed_src[i].operand = (token != NULL)? strdup(token): "";
        i++;
    }

    src_len = i;
}

void parse_optab() {
    char line[LEN];
    int i = 0;

    while(fgets(line, sizeof(line), optab_fp)) {
        char* token = strtok(line, delim);
        parsed_optab[i].opcode = (token != NULL)? strdup(token): "";
        token = strtok(NULL, delim);
        parsed_optab[i].hex = (token != NULL)? strdup(token): "";
        i++;
    }

    optab_len = i;
}

bool search_optab(char* opcode) {
    for (int i = 0; i < optab_len; i++) {
        if(strcmp(opcode, parsed_optab[i].opcode) == 0)
            return true;            
    }
    return false;
}

bool search_symtab(char* symbol) {
    for (int i = 0; i < symtab_len; i++) {
        if(strcmp(symbol, parsed_symtab[i].symbol) == 0)
            return true;
    }
    return false;
}

void write_intermediate_file() {
    for (int i = 0; i < src_len; i++) {
        fprintf(intmd_fp, "0x%x^%s^%s^%s\n", parsed_src[i].addr, parsed_src[i].label, parsed_src[i].opcode, parsed_src[i].operand);
    }
}

void write_symtab() {
    for (int i = 0; i < symtab_len; i++) {
        fprintf(symtab_fp, "%s^0x%x\n", parsed_symtab[i].symbol, parsed_symtab[i].addr);
    }
}

void print_parsed_src() {
    for (int i = 0; i < src_len; i++) {
        printf("%s^%s^%s\n", parsed_src[i].label, parsed_src[i].opcode, parsed_src[i].operand);
    }
}

void print_symtab() {
    for (int i = 0; i < symtab_len; i++) {
        printf("%s^%i\n", parsed_symtab[i].symbol, parsed_symtab[i].addr);
    }
}

int main() {
    optab_fp = fopen("optab.txt", "r");
    src_fp = fopen("source.txt", "r");
    intmd_fp = fopen("intermediate.txt", "w");
    symtab_fp = fopen("symtab.txt", "w");

    parse_src();
    parse_optab();

    char* opcode;

    if(strcmp(parsed_src[0].opcode, "START") == 0) {
        locctr = strtoul(parsed_src[0].operand, NULL, 16);
    }
    else {
        locctr = 0;
    }
    parsed_src[0].addr = locctr;

    for(int i = 1; i < src_len; i++) {
        if(strcmp(parsed_src[i].label, "$") != 0) {
            if(search_symtab(parsed_src[i].opcode)) {
                perror("duplicate symbol");
                exit(1);
            }
            parsed_symtab[symtab_len].addr = locctr;
            strcpy(parsed_symtab[symtab_len].symbol, parsed_src[i].label);
            symtab_len++;
        }

        char* opcode;
        if(search_optab(parsed_src[i].opcode)) {
            locctr += 3; 
        }
        else if(strcmp(parsed_src[i].opcode, "WORD") == 0) {
            locctr += 3; 
        }
        else if(strcmp(parsed_src[i].opcode, "RESW") == 0) {
            int word_arr_len = strtoul(parsed_src[i].operand, NULL, 16);
            locctr += 3*word_arr_len;
        }
        else if(strcmp(parsed_src[i].opcode, "RESB") == 0) {
            int byte_arr_len = strtoul(parsed_src[i].operand, NULL, 16);
            locctr += byte_arr_len;
        }
        else if(strcmp(parsed_src[i].opcode, "BYTE") == 0) {
            int bytes_len = 0;
            if(parsed_src[i].operand[0] == 'X') {
                int bytes_len = strlen(parsed_src[i].operand);
                bytes_len = (bytes_len - 3)/2;
            }
            if(parsed_src[i].operand[0] == 'C') {
                int bytes_len = strlen(parsed_src[i].operand);
                bytes_len = bytes_len - 3;
            }
            locctr += bytes_len;
        }
        else {
            printf("opcode not found -> opcode: %s", parsed_src[i].opcode);
            exit(1);
        }
        parsed_src[i].addr = locctr;
    }
    
    write_intermediate_file();
    write_symtab();

    return 0;
}

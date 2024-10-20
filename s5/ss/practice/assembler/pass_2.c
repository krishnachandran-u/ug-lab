#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN 100

const char* delim = "^ \n";

FILE* intmd_fp;
FILE* optab_fp;
FILE* symtab_fp;
FILE* object_prog_fp;

struct intmd {
    int addr;
    char* label;
    char* opcode;
    char* operand;
} parsed_intmd[100];

struct optab_line {
    char* opcode;
    char* hex; 
} parsed_optab[100];

struct symtab_line {
    char symbol[10];
    int addr;
} parsed_symtab[100];

int intmd_len = 0;
int optab_len = 0;
int symtab_len = 0;

void parse_intermediate_file() {
    char line[LEN];
    int i = 0;

    while (fgets(line, sizeof(line), intmd_fp)) {
        char* token = strtok(line, delim);
        parsed_intmd[i].addr = (token != NULL)? strtoul(token, NULL, 16): -1;
        token = strtok(NULL, delim);
        parsed_intmd[i].label = (token != NULL)? strdup(token): "";
        token = strtok(NULL, delim);
        parsed_intmd[i].opcode = (token != NULL)? strdup(token): "";
        token = strtok(NULL, delim);
        parsed_intmd[i].operand = (token != NULL)? strdup(token): "";
        i++;
    }
    intmd_len = i;
}

void parse_optab() {
    char line[LEN];
    int i = 0;

    while (fgets(line, sizeof(line), optab_fp)) {
        char* token = strtok(line, delim);
        parsed_optab[i].opcode = (token != NULL)? strdup(token): "";
        token = strtok(NULL, delim);
        parsed_optab[i].hex = (token != NULL)? strdup(token): "";
        i++;
    }

    optab_len = i;
}

void parse_symtab() {
    char line[LEN];
    int i = 0;

    while (fgets(line, sizeof(line), symtab_fp)) {
        char* token = strtok(line, delim);
        strcpy(parsed_symtab[i].symbol, (token != NULL)? token: "");
        token = strtok(NULL, delim);
        parsed_symtab[i].addr = (token != NULL)? strtoul(token, NULL, 16): -1; 
        i++;
    }

    symtab_len = i;
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

char* get_opcode_hex(char* opcode) {
    for (int i = 0; i < optab_len; i++) {
        if(strcmp(opcode, parsed_optab[i].opcode) == 0)
            return parsed_optab[i].hex;
    }
    return "";
}

int get_symbol_addr(char* symbol) {
    for (int i = 0; i < symtab_len; i++) {
        if(strcmp(symbol, parsed_symtab[i].symbol) == 0) {
            return parsed_symtab[i].addr;
        }
    }
    return -1;
}

void pad_string(char* str, int len) {
    int str_len = strlen(str);
    for (int i = str_len; i < len; i++) {
        str[i] = '_';
    }
    str[len] = '\0';
}

int main() {
    optab_fp = fopen("optab.txt", "r");
    intmd_fp = fopen("intermediate.txt", "r");
    symtab_fp = fopen("symtab.txt", "r");
    object_prog_fp = fopen("object_prog.txt", "w");

    parse_intermediate_file();
    parse_optab();
    parse_symtab();

    int program_length = parsed_intmd[intmd_len - 1].addr - parsed_intmd[0].addr;

    if (strcmp(parsed_intmd[0].opcode, "START") == 0) {
        fprintf(object_prog_fp, "H^%-6s^%06X^%06X\n", parsed_intmd[0].label, parsed_intmd[0].addr, program_length);
    }

    int text_record_len = 0;
    char* text_record = (char*)malloc(LEN * sizeof(char));
    for (int i = 1; i < intmd_len - 1; i++) {
        char object_code[LEN];
        if (search_optab(parsed_intmd[i].opcode)) {
            char* opcode_hex = get_opcode_hex(parsed_intmd[i].opcode);
            int operand_addr = 0000;
            if (search_symtab(parsed_intmd[i].operand)) {
                operand_addr = get_symbol_addr(parsed_intmd[i].operand);
            }
            sprintf(object_code, "%s%04X", opcode_hex, operand_addr);
            if (text_record_len + strlen(object_code) > 60) {
                fprintf(object_prog_fp, "T^%06X^%02X^%s\n", parsed_intmd[i - 1].addr, text_record_len, text_record);
                text_record_len = 0;
                text_record = (char*)malloc(LEN * sizeof(char));
            }
            strcat(text_record, "^");
            strcat(text_record, object_code);
        }
        else if (strcmp(parsed_intmd[i].opcode, "WORD") == 0 || strcmp(parsed_intmd[i].opcode, "BYTE") == 0) {
            sprintf(object_code, "%06X", get_symbol_addr(parsed_intmd[i].label));
            if (text_record_len + strlen(object_code) > 60) {
                fprintf(object_prog_fp, "T^%06X^%02X^%s\n", parsed_intmd[i - 1].addr, text_record_len, text_record);
                text_record_len = 0;
                text_record = (char*)malloc(LEN * sizeof(char));
            }
            strcat(text_record, "^");
            strcat(text_record, object_code);
        }
        else if (strcmp(parsed_intmd[i].opcode, "RESW") == 0 || strcmp(parsed_intmd[i].opcode, "RESB") == 0) {
            if (text_record_len > 0) {
                fprintf(object_prog_fp, "T^%06X^%02X^%s\n", parsed_intmd[i - 1].addr, text_record_len, text_record);
                text_record_len = 0;
                text_record = (char*)malloc(LEN * sizeof(char));
            }
            continue;
        }
        text_record_len += strlen(object_code);
    }
    if (text_record_len > 0) {
        fprintf(object_prog_fp, "T^%06X^%02X^%s\n", parsed_intmd[intmd_len - 1].addr, text_record_len, text_record);
    }
    fprintf(object_prog_fp, "E^%06X\n", parsed_intmd[0].addr);
}



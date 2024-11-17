#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 100

const char* delim = "^ \n";

int optab_len = 0;
int symtab_len = 0;
int intmd_len = 0;

struct optab_line {
    char* opcode;
    int hex;
} optab[100];

struct symtab_line {
    char* symbol;
    int addr;
} symtab[100];

struct intmd {
    int addr;
    char* label;
    char* opcode;
    char* operand;
} intmd[100];

void load_optab() {
    FILE* fp = fopen("optab.txt", "r");
    char line[MAXLEN];
    int i = 0;
    while(fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, delim);
        optab[i].opcode = strdup(token);
        token = strtok(NULL, delim);
        optab[i].hex = strtoul(token, NULL, 16);
        i++;
    }
    optab_len = i;
    fclose(fp);
    return;
}

void load_symtab() {
    FILE* fp = fopen("symtab.txt", "r");
    char line[MAXLEN];
    int i = 0;
    while(fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, delim);
        symtab[i].symbol = strdup(token); 
        token = strtok(NULL, delim);
        symtab[i].addr = strtoul(token, NULL, 16);
        i++;
    }
    symtab_len = i;
    fclose(fp);
    return;
}

void load_intmd() {
    FILE* fp = fopen("intermediate.txt", "r");
    char line[MAXLEN];
    int i = 0;
    while(fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, delim);
        intmd[i].addr = strtoul(token, NULL, 16); 
        token = strtok(NULL, delim);
        intmd[i].label = strdup(token);
        token = strtok(NULL, delim);
        intmd[i].opcode = strdup(token);
        token = strtok(NULL, delim);
        intmd[i].operand = strdup(token);
        i++;
    } 
    intmd_len = i;
    fclose(fp);
    return;
}

int get_opcode_hex(char* opcode) {
    for (int i = 0; i < optab_len; i++) {
        if(strcmp(optab[i].opcode, opcode) == 0)
                return optab[i].hex; 
    }
    return 0;
}

int get_symbol_addr(char* symbol) {
    for (int i = 0; i < symtab_len; i++) {
        if(strcmp(symtab[i].symbol, symbol) == 0)
            return symtab[i].addr;
    }
    return 0;
}

void run_pass_2() {
    FILE* fp = fopen("obj_prog.txt", "w");
    if (strcmp(intmd[0].opcode, "START") == 0) {
        int start_addr;
        start_addr = strtoul(intmd[0].operand, NULL, 16);
        fprintf(fp, "H^%-6s^%06X\n", intmd[0].label, start_addr);
    }
    int len = 0;
    char T[MAXLEN];
    strcpy(T, "");
    for (int i = 1; i < intmd_len - 1; i++) {
        if (strcmp(intmd[i].opcode, "RESW") == 0 || strcmp(intmd[i].opcode, "RESB") == 0) {
            fprintf(fp, "T^%02X^%s\n", len/2, T);
            strcpy(T, "");
            len = 0;
            continue;
        }
        else if (len + 6 > 60) {
            fprintf(fp, "T^%02X^%s\n", len/2, T);
            strcpy(T, "");
            len = 0;
        }
        else {
            if (strcmp(intmd[i].opcode, "BYTE") == 0 || strcmp(intmd[i].opcode, "WORD") == 0) {
                sprintf(T, "%s^%06X", T, get_symbol_addr(intmd[i].operand));
            }
            else {
                sprintf(T, "%s^%02X%04X", T, get_opcode_hex(intmd[i].opcode), get_symbol_addr(intmd[i].operand));
            }
            len += 6;
        }
    }
    
    if (len > 0) {
        fprintf(fp, "T^%02X^%s\n", len/2, T);
        strcpy(T, "");
        len = 0;
    }

    int start_addr;
    start_addr = strtoul(intmd[0].operand, NULL, 16);
    fprintf(fp, "E^%06X", start_addr);
    fclose(fp);
}

int main() {
    printf("here");
    load_optab(); 
    /*
    for (int i = 0; i < optab_len; i++) {
        printf("%s^%04X\n", optab[i].opcode, optab[i].hex);
    }
    */
    load_symtab();
    /*
    for (int i = 0; i < symtab_len; i++) {
        printf("%s^%04X\n", symtab[i].symbol, symtab[i].addr);
    }
    */
    load_intmd();
    run_pass_2();        
}

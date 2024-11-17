#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 100

int symtab_len = 0;
int optab_len = 0;
int src_len = 0;

char* delim = "^ \n";

struct symtab_entry {
    char* symbol;
    int addr;
} symtab[100];

struct optab_entry {
    char* opcode;
    int hex;
} optab[100];

struct src_line {
    int addr;
    char* label;
    char* opcode;
    char* operand;
} src[100];

void load_optab() {
    FILE* optab_fp = fopen("optab.txt", "r");
    char line[MAXLEN];
    int i = 0;
    while(fgets(line, sizeof(line), optab_fp)) {
        char* token = strtok(line, delim);
        optab[i].opcode = strdup(token);
        token = strtok(NULL, delim);
        optab[i].hex = strtoul(token, NULL, 16);
        i++;
    }
    optab_len = i;
    fclose(optab_fp);
    return;
}

void load_src() {
    FILE* src_fp = fopen("source.txt", "r");
    char line[MAXLEN];
    int i = 0;
    while(fgets(line, sizeof(line), src_fp)) {
        char* token = strtok(line, delim);
        src[i].label = strdup(token);
        token = strtok(NULL, delim);
        src[i].opcode = strdup(token);
        token = strtok(NULL, delim);
        src[i].operand = strdup(token);
        i++;
    }
    src_len = i;
    fclose(src_fp);
    return;
}

bool search_optab(char* opcode) {
    for (int i = 0; i < optab_len; i++) {
        if (strcmp(optab[i].opcode, opcode) == 0) return true; 
    }
    return false;
}

bool search_symtab(char* symbol) {
    for (int i = 0; i < symtab_len; i++) {
        if (strcmp(symtab[i].symbol, symbol) == 0) {
            printf("duplicate symbol %s", symbol);
            exit(1);
        }
    }
    return false; 
}

void run_pass_one() {
    int i = 0;
    int locctr = 0;
    locctr = (strcmp("START", src[i].opcode) == 0)? strtoul(src[i].operand, NULL, 16): 0;
    i++;
    while(i < src_len) {
        src[i].addr = locctr;
        if(strcmp(src[i].label , "$") != 0) {
            if(!search_symtab(src[i].label)) {
                symtab[symtab_len].addr = locctr;
                symtab[symtab_len].symbol = src[i].label;
                symtab_len++;
            }
        }

        if(search_optab(src[i].opcode)) {
            locctr += 3;
        }
        else if(strcmp(src[i].opcode, "RESB") == 0) {
            locctr += strtoul(src[i].operand, NULL, 16); 
        }
        else if(strcmp(src[i].opcode, "RESW") == 0) {
            locctr += 3*strtoul(src[i].operand, NULL, 16); 
        }
        else if(strcmp(src[i].opcode, "WORD") == 0) {
            locctr += 3;
        }
        else if(strcmp(src[i].opcode, "BYTE") == 0) {
            if (src[i].operand[0] == 'X')
                locctr += (strlen(src[i].operand) - 3)/2;
            if (src[i].operand[0] == 'C')
                locctr += (strlen(src[i].operand) - 3);
        }
        else {
            printf("opcode not found %s: at line %d", src[i].opcode, i);
            exit(1);
        }
        i++;
    }
    return;
}

void write_symtab() {
    FILE* symtab_fp = fopen("symtab.txt", "w");

    for (int i = 0; i < symtab_len; i++) {
        fprintf(symtab_fp, "%s^%04X\n", symtab[i].symbol, symtab[i].addr);
    }

    return;
}

void write_intermediate_file() {
    FILE* int_fp = fopen("intermediate.txt", "w"); 

    for (int i = 0; i < src_len; i++) {
        fprintf(int_fp, "%04X^%s^%s^%s\n", src[i].addr, src[i].label, src[i].opcode, src[i].operand);
    }

    return;
}

int main() {
    load_optab();
    /*
    for (int i = 0; i < optab_len; i++) {
        printf("%s^%02X\n", optab[i].opcode, optab[i].hex);
    }
    */
    load_src();
    /*
    for (int i = 0; i < src_len; i++) {
        printf("%s^%s^%s\n", src[i].label, src[i].opcode, src[i].operand);
    }
    */
    run_pass_one();
    write_symtab();
    write_intermediate_file();
    return 0;
}


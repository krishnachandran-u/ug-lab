#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LEN 100

const char* delim = "^ \n";

struct TextRecords {
    char* object_code[LEN];
    int addr;
    int len;
    int bitmask;
} text_records[LEN];

FILE* object_prog_fp;

char* object_prog[LEN];
int object_prog_len = 0;

int dec_to_bin(int n) {
    int bin = 0;
    while(n) {
        bin = bin * 10 + n % 2;
        n /= 2;
    }
    return bin;
}

void parse_object_prog() {
    char line[LEN];
    int i = 0;
    while(fgets(line, LEN, object_prog_fp)) {
        object_prog[i] = strdup(line);
        i++;
    }
    object_prog_len = i;
}

void load_text_records() {
    for (int i = 1; i < object_prog_len - 1; i++) {
        char* line = object_prog[i];
        
        char len_string[3];
        len_string[0] = line[9];
        len_string[1] = line[10];
        len_string[2] = '\0';

        int len = strtoul(len_string, NULL, 16); 
        text_records[i - 1].len = len;

        char bitmask_string[4];
        bitmask_string[0] = line[12];
        bitmask_string[1] = line[13];
        bitmask_string[2] = line[14];
        bitmask_string[3] = '\0';

        int bitmask = strtoul(bitmask_string, NULL, 16);
        text_records[i - 1].bitmask = bitmask;
        //sprintf(text_records[i - 1].bitmask, "%012d", dec_to_bin(bitmask));
        
        char* ptr = line + 16; //T^001015^2A^CC0^040000^0C1015^001015^181018^0C101B^10101B^000000
        char* token = strtok(ptr, delim);
        int j = 0;
        while(token != NULL) {
            text_records[i - 1].object_code[j] = strdup(token);
            token = strtok(NULL, delim);
            j++;
        }
    }
}

void inc_addrs(const int new_base_addr) {
    for (int i = 0; i < object_prog_len - 2; i++) {
        char bitmask_string[13];
        sprintf(bitmask_string, "%012d", dec_to_bin(text_records[i].bitmask));
        for (int j = 0; j < text_records[i].len/6; j++) {
            char* addr_object_code_string = text_records[i].object_code[j] + 2;
            char opcode[3];
            opcode[0] = text_records[i].object_code[j][0];
            opcode[1] = text_records[i].object_code[j][1];
            opcode[2] = '\0';

            int addr_object_code = strtoul(addr_object_code_string, NULL, 16);
            int new_addr = new_base_addr + addr_object_code;
            char new_addr_string[5];
            sprintf(new_addr_string, "%04X", new_addr);
            char new_object_code[7];
            sprintf(new_object_code, "%s%s", opcode, new_addr_string);
            text_records[i].object_code[j] = strdup(new_object_code);
        }
    }
}

void print_object_codes() {
    for (int i = 0; i < object_prog_len - 2; i++) {
        for (int j = 0; j < text_records[i].len/6; j++) {
            printf("%-6s\n", text_records[i].object_code[j]);
        }
    }
}


int main() {
    object_prog_fp = fopen("object_prog.txt", "r");
    parse_object_prog();
    load_text_records();        
    inc_addrs(0x6000);
    print_object_codes();

    return 0; 
}

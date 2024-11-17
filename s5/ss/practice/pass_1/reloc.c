#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

const char* delim = "^ \n";

char* get_bitmask(char* hex) {
    char* bitmask = (char*)malloc(9*sizeof(char));
    strcpy(bitmask, "");
    int num = strtoul(hex, NULL, 10);
    for (int i = 0; i < 8; i++) {
        int rem = num % 2;
        int num = num / 2;
        bitmask[8 - i - 1] = rem + '0';
    }
    bitmask[8] = '\0';
    return bitmask;
}

int main() { 
    FILE* fp = fopen("obj_prog.txt", "r");
    int ns;
    printf("Enter the address to which the code is to be relocated: "); 
    scanf("%d", &ns);
    char line[MAXLEN];
    int i = 0;
    int s;
    while(fgets(line, sizeof(line), fp)) {
        if(line[0] == 'H') {
            s = strtoul(line + 9, NULL, 16);
        }
        if(line[0] == 'E') {
            break;
        }
        if(line[0] == 'T') {
            char bm_string[4];
            bm_string[0] = line[6];
            bm_string[1] = line[7];
            bm_string[2] = line[8];
            bm_string[3] = '\0';
            char* bm = get_bitmask(bm_string);
            int i = 0;
            char* token = strtok(line + 9, delim);
            while(token != NULL) {
                int operand_addr = strtoul(token + 2, NULL, 16);
                int new_addr;
                if(bm[i] == '1') {
                    new_addr = operand_addr - s + ns;
                }
                else { 
                    new_addr = operand_addr; 
                }
                printf("%c%c%04X\n", token[0], token[1], new_addr);
            }
        }
    }
    return 0;
}

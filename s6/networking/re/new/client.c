#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX 2048 
#define LEN 50
#define WIN 5

char* readfrom() {
    FILE* sbuff = fopen("sbuff", "w");
    char* msg = (char*)malloc(MAX);
    if (fgets(msg, MAX, sbuff) != NULL) {
        fclose(sbuff);
        return msg;
    }
    else {
        fclose(sbuff);
        return NULL;
    }
}

void writeto(int x) {
    FILE* cbuff = fopen("cbuff", "w");
    fprintf(cbuff, "%d", x);
    fclose(cbuff);
    return;
}

void clear() {
    FILE* cbuff = fopen("cbuff", "w");
    fclose(cbuff);
    return;
}

int l = 0, p = WIN;

int main() {
    printf("Sending packet: %d\n", p);
    writeto(p);
    char* msg = readfrom();
    if (msg != NULL) {
        int q = atoi(msg);
    }
}

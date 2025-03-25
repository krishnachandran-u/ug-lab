#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX 2048 

char* readfrom() {
    FILE* cbuff = fopen("cbuff", "w");
    char* msg = (char*)malloc(MAX);
    fgets(msg, MAX, cbuff);
    fclose(cbuff);
    return msg;
}

void writeto(int x) {
    FILE* sbuff = fopen("sbuff", "w");
    fprintf(sbuff, "%d", x);
    fclose(sbuff);
    return;
}

void clear() {
    FILE* sbuff = fopen("sbuff", "w");
    fclose(sbuff);
    return;
}

int main() {
    srand(time(NULL));
    FILE* cbuff = fopen("cbuff", "w");
    FILE* sbuff = fopen("sbuff", "w");
    int seq = 0;
    while(true) {
        char* msg = readfrom();
        if (msg != NULL) {
            int q = atoi(msg);
            printf("Packet received: %d\n", q);
            printf("New packet | seq updated\n");
            sleep(1);
            if (rand() % 2) {
                printf("Sending ack for %d\n", q);
                writeto(q);
            }
            else {
                clear();
            }
        }
        free(msg);
    }
}

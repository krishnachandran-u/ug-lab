#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TIMEOUT 1

int main() {
    int i = 5;
    while(i--) {
        sleep(TIMEOUT);
        printf("gyattmaxxing\n");
    }
}


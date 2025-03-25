#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int status;
    int pid = fork();
    if (pid == -1) {
        printf("bad fork");
        exit(1);
    }
    if (pid == 0) {
        printf("child\n");
    }
    else {
        wait(&status);
        printf("parent\n");
    }
    return 0;
}

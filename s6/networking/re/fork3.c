#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int status;
    int pid = fork();
    if (pid == -1) {
        printf("bad fork\n");
        exit(1);
    }
    if (pid == 0) {
        printf("Enter child\n");
        char w[100];
        fgets(w, 100, stdin);
        for (int i = 0; i < 100; i++) {
            if (w[i] >= 'a' && w[i] <= 'z') {
                w[i] += 'A' - 'a';
            }
        }
        printf("%s\n", w);
        printf("Exit child\n");
    }
    if (pid > 0) {
        wait(&status);
        printf("Parent\n");
    }
    return 0;
}

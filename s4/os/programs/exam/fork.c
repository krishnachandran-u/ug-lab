#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); 

    if (pid < 0) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        printf("child pid: %d\n", getpid());
    }
    else {
        wait(NULL);
        printf("parent pid: %d\n", getpid());
    }
}


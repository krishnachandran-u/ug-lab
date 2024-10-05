#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char* args[] = {"ls", "-la", NULL};
    execv("/bin/ls", args);
    return 0;
}

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Process id: %d", getpid());
    return 0;
}

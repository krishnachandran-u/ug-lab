#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    pid_t child_pid;

    printf("Forking a child process...\n");
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        printf("Child process created with PID: %d\n", getpid());
        execlp("./child_process", "./child_process", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process with PID: %d\n", getpid());
        wait(NULL);
        printf("Child process terminated\n");
    }

    printf("Exiting the program...\n");

    int fd = open("somefile.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    close(fd);

    struct stat file_stat;
    if (stat("somefile.txt", &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    printf("File size: %ld bytes\n", file_stat.st_size);

    DIR *dir = opendir("./somedir");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    printf("Directory contents:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);

    return 0;
}


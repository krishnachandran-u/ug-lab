#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("sem.c", O_RDONLY);
    printf("fd: %d\n", fd);
    char buffer[1];
    ssize_t bytes_read = read(fd, buffer, 1);
    close(fd);
    printf("%d", bytes_read < 0);
    return bytes_read < 0;
}

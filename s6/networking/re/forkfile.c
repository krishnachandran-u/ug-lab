#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buff[50];
    printf("Enter text to written in to a file: ");
    int n = read(0, buff, 50);
    int fd = open("input.txt", O_CREAT | O_RDWR, 0777);
    write(fd, buff, n);
    close(fd);
    FILE* fp = fopen("file.txt", "r");
    char ch; 
    do {
        ch = fgetc(fp);
        printf("%c", ch);
    } while(ch != EOF);
    fclose(fp);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 2048
#define NLEN 256
#define PORT 8000
#define CNUM 5

int main() {
    int serversocket, clientsocket;
    struct sockaddr_in serveraddr, clientaddr;
    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);
    serversocket = socket(AF_INET, SOCK_STREAM, 0);
    int bind_status = bind(serversocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    listen(serversocket, CNUM);
    socklen_t len = sizeof(clientaddr);
    clientsocket = accept(serversocket, (struct sockaddr*)&clientaddr, &len);
    char fname[NLEN], buff[MAX];
    read(clientsocket, fname, NLEN);
    FILE* fp = fopen(fname, "r");
    if (fp == NULL) {
        write(clientsocket, "File not found", sizeof("File not found"));
    }
    else {
        while(fgets(buff, MAX, fp) != NULL) {
            write(clientsocket, buff, MAX);
        }
    }
    fclose(fp);
    close(serversocket);
    close(clientsocket);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 2048
#define PORT 8000
#define FILENAME "file.txt"

int main() {
    int clientsocket;
    struct sockaddr_in serveraddr;
    clientsocket = socket(AF_INET, SOCK_STREAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);
    int connect_status = connect(clientsocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    printf("Sending filename to server\n");
    send(clientsocket, FILENAME, sizeof(FILENAME), 0);
    printf("Receiving data\n");
    char msg[MAX];
    recv(clientsocket, msg, MAX, 0);
    printf("Content of the file: \n%s", msg);
    close(clientsocket);
    return 0;
}

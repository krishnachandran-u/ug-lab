#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define SIZE 100

int main() {
    int serversocket;
    struct sockaddr_in serveraddr, clientaddr;
    char msg[SIZE];

    serversocket = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;

    int port;
    printf("Enter port number: ");
    scanf("%d", &port);

    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    int bind_status = bind(serversocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    printf("Waiting for client connection\n");
    bzero((char*)&clientaddr, sizeof(clientaddr));
    socklen_t len = sizeof(clientaddr);

    recvfrom(serversocket, msg, sizeof(msg), 0, (struct sockaddr*)&clientaddr, &len);
    printf("Connection received from client\n");
    printf("Client said: %s\n", msg);

    printf("Sending to client\n");
    sendto(serversocket, "HELLO FROM SERVER", sizeof("HELLO FROM SERVER"), 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));
    close(serversocket);
}

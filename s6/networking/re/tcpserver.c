#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#define SIZE 100
#define MAXCONN 5

int main() {
    int serversocket, clientsocket;
    struct sockaddr_in serveraddr, clientaddr; 
    char msg[SIZE];

    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    int port;
    printf("Enter the port number: ");
    scanf("%d", &port);

    serveraddr.sin_port = htons(port); 

    serversocket = socket(AF_INET, SOCK_STREAM, 0);
    int bind_status = bind(serversocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    bzero((char*)&clientaddr, sizeof(clientaddr));

    listen(serversocket, MAXCONN);

    printf("Waiting for client connections\n");

    socklen_t len = sizeof(clientaddr);
    clientsocket = accept(serversocket, (struct sockaddr*)&clientaddr, &len);

    printf("Client connection received\n");
    printf("Reading message from client\n");

    read(clientsocket, msg, SIZE);

    printf("Client: %s\n", msg);
    printf("Sending message to client\n");
     
    write(clientsocket, "MSG RECEIVED", sizeof("MSG RECEIVED"));

    close(clientsocket);
    close(serversocket);
}

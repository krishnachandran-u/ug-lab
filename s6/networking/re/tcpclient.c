#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define SIZE 100

int main() {
    struct sockaddr_in serveraddr;
    char msg[SIZE];

    int clientsocket = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    // serveraddr.sin_addr.s_addr = INADDR_ANY;

    int port;
    printf("Enter the port number: ");
    scanf("%d", &port);

    serveraddr.sin_port = htons(port);
    printf("Trying to connect to the server\n");

    int connect_status = connect(clientsocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    printf("Connected to the server\n");
    printf("Sending message to the server\n");

    send(clientsocket, "HI STILL WATER", sizeof("HI STILL WATER"), 0);

    printf("Receiving message from the server\n");
    recv(clientsocket, msg, sizeof(msg), 0);

    printf("Message received: %s \n", msg);
    close(clientsocket);

}

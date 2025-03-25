#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define SIZE 100

int main() {
    int clientsocket, port;
    struct sockaddr_in serveraddr;
    char msg[SIZE];

    clientsocket = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    // serveraddr.sin_addr.s_addr = INADDR_ANY;

    printf("Enter the port number: ");
    scanf("%d", &port);

    serveraddr.sin_port = htons(port);

    socklen_t len = sizeof(serveraddr);

    printf("Sending message to server\n");
    sendto(clientsocket, "HELLO FROM CLIENT" , sizeof("HELLO FROM CLIENT"), 0, (struct sockaddr*)&serveraddr, len); 

    printf("Receiving message from server\n"); 
    recvfrom(clientsocket, msg, sizeof(msg), 0, (struct sockaddr*)&serveraddr, &len);
    printf("Message received\n");
    close(clientsocket);
    return 0;
}

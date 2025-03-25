#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define PORT 8000
#define MAX 2048

int main() {
    int clientsocket;
    struct sockaddr_in serveraddr;
    
    clientsocket = socket(AF_INET, SOCK_DGRAM, 0);
    
    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);
    
    socklen_t len = sizeof(serveraddr);
    
    int pcnt = 0;

    char buff[MAX];

    printf("Client ready\n");
    while(pcnt < 10) {
        bzero(buff, MAX);
        sprintf(buff, "%d", pcnt);
        printf("Sending packet %d to server\n", pcnt);
        sendto(clientsocket, buff, MAX, 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

        bzero(buff, MAX);
        socklen_t len = sizeof(serveraddr);
        recvfrom(clientsocket, buff, MAX, 0, (struct sockaddr*)&serveraddr, &len);
        printf("Received ack from server: %s\n", buff);
        sleep(1);
        pcnt++;
    }
}

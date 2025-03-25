#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h> 
#include <arpa/inet.h>
#include <time.h>
#include <stdbool.h>

#define PORT 8000
#define MAX 1024

int main() {
    int serversocket; 
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t len;

    serversocket = socket(AF_INET, SOCK_DGRAM, 0);

    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);

    int bind_status = bind(serversocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    char buff[MAX];

    while(true) {
        bzero(buff, MAX);
        socklen_t len = sizeof(clientaddr); 
        recvfrom(serversocket, buff, MAX, 0, (struct sockaddr*)&clientaddr, &len);
        printf("Packet received %s\n", buff);
        sleep(1);
        printf("Sending ack to client\n");
        sendto(serversocket, buff, MAX, 0, (struct sockaddr*)&clientaddr, len);
    }
    close(serversocket);
    return 0;
}

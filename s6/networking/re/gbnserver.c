#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <time.h>

#define PORT 8000
#define MAX 2048

int main() {
    srand(time(NULL));
    int serversocket;
    struct sockaddr_in serveraddr, clientaddr;
    serversocket = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);
    int bind_status = bind(serversocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    int seq = 0;
    char buff[MAX];
    socklen_t len = sizeof(clientaddr);
    while(true) {
        recvfrom(serversocket, buff, MAX, 0, (struct sockaddr*)&clientaddr, &len);
        printf("Received packet %s\n", buff);
        sleep(1);
        sprintf(buff, "%d", atoi(buff));
        if (rand() % 2) sendto(serversocket, buff, MAX, 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));
        if (seq == atoi(buff)) {
            printf("New packet - seq %d updated\n", seq);
            seq++;
        }
        else {
            printf("Old packet - seq %d not updated\n", seq);
        }
    }
    return 0;
}

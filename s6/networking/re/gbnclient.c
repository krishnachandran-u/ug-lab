#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 2048
#define PORT 8000
#define WIN 5
#define LEN 50

#define max(a,b) (a > b)? a: b

bool acked[LEN];
int l = 0, p = 0;

int main() {
    int clientsocket;
    struct sockaddr_in serveraddr;
    bzero((char*)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);
    socklen_t len = sizeof(serveraddr);
    clientsocket = socket(AF_INET, SOCK_DGRAM, 0);
    for (int i = 0; i < LEN; i++) acked[i] = false; 
    char buff[MAX];
    while(p < LEN) {
        bzero(buff, MAX);
        sprintf(buff, "%d", p);
        sendto(clientsocket, buff, MAX, 0, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
        printf("Sent packet: %d\n", p); 
        recvfrom(clientsocket, buff, MAX, 0, (struct sockaddr*)&serveraddr, &len);
        int q = atoi(buff);
        printf("Received ack: %d\n", q);
        acked[q] = true;
        p++;
        if (p == l + WIN) {
            int lcr = l;
            while(l < max(LEN, lcr + WIN) && acked[l] == true) l++;
            p = l;
        }
        sleep(1);
    }
}

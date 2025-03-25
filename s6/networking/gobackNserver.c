#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

void main() {
    char *ip = "127.0.0.100";
    int port = 5573;
    srand(time(0));

    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    socklen_t addr_size;
    int n, i, b;
    int recd[10];
    
    for (i = 0; i < 10; i++) {
        recd[i] = -1;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("[ -] Socket error");
        exit(1);
    }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    n = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (n < 0) {
        perror("[+] Bind error");
        exit(1);
    }

    while (1) {
        bzero(buffer, 1024);
        addr_size = sizeof(client_addr);
        recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&client_addr, &addr_size);
        b = atoi(buffer);

        if (recd[b] == b)
            printf("Server: Received packet %s (duplicate)\n", buffer);
        else {
            recd[b] = b;
            printf("Server: Received packet %s\n", buffer);
        }

        sleep(1);

        if (rand() % 2 == 0) {
            printf("Server: Sending acknowledgement from packet %s\n", buffer);
            sendto(sockfd, buffer, 1024, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
        }
    }
}


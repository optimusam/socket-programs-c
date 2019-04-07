#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int sd, cd;
    struct sockaddr_in server, client;
    char buff[1000];

    socklen_t clilen = sizeof(client);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(2000);

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    bind(sd, (struct sockaddr*)&server, sizeof(server));
    listen(sd, 5);
    printf("Server is running...\n");

    while(1) {
        bzero(&buff, sizeof(buff));
        recvfrom(sd, buff, sizeof(buff), 0, (struct sockaddr*)&client, &clilen);
        printf("message received: %s\n", buff);
        sendto(sd, buff, sizeof(buff), 0, (struct sockaddr*)&client, clilen);
    }
}
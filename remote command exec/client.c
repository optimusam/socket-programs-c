#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int sd, cd;
    char buff[1000];
    struct sockaddr_in server, client;
    socklen_t clilen;
    clilen = sizeof(client);
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(2000);
    socklen_t slen = sizeof(server);
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    bind(sd, (struct sockaddr*)&server, sizeof(server));

    while(1) {
        bzero(&buff, sizeof(buff));
        printf("enter command: ");
        fgets(buff, sizeof(buff), stdin);
        sendto(sd, buff, sizeof(buff), 0, (struct sockaddr*)&server, slen);
        printf("command sent\n");
    }

}
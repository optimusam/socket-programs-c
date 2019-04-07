#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    struct sockaddr_in client, server;
    int sockfd;
    bzero(&server, sizeof(server));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(2000);
    socklen_t slen = sizeof(server);

    connect(sockfd, (struct sockaddr *)&server, slen);

    while(1) {
        char msg[1000];
        printf("Enter msg:\n");
        fgets(msg, sizeof(msg), stdin);
        send(sockfd, msg, sizeof(msg), 0);
        bzero(&msg, sizeof(msg));
        printf("sent message\n");
    }

    close(sockfd);

}
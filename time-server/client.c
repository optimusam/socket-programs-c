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
    char buff[1000];
    bzero(&server, sizeof(server));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(2000);
    socklen_t slen = sizeof(server);

    connect(sockfd, (struct sockaddr *)&server, slen);

    recv(sockfd, buff, sizeof(buff), 0);

    printf("Date/Time: %s", buff);

    close(sockfd);

}
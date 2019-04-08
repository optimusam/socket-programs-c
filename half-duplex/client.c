#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int sd;
    struct sockaddr_in server;
    char buff1[1000], buff2[1000];
    socklen_t slen = sizeof(server);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(2000);

    sd = socket(AF_INET, SOCK_STREAM, 0);

    bind(sd, (struct sockaddr*)&server, sizeof(server));

    connect(sd, (struct sockaddr*)&server, slen);

    while(1) {
        bzero(&buff1, sizeof(buff1));
        bzero(&buff2, sizeof(buff2));
        printf("\nEnter message: ");
        fgets(buff2, sizeof(buff2), stdin);
        send(sd, buff2, sizeof(buff2), 0);
        recv(sd, buff1, sizeof(buff1), 0);
        printf("Server: %s", buff1);
    }
}
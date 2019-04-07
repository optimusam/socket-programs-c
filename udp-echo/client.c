#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int sd;
    struct sockaddr_in server, client;
    char buff[1000];

    socklen_t slen = sizeof(client);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(2000);

    sd = socket(AF_INET, SOCK_DGRAM, 0);



    while(1) {
        bzero(&buff, sizeof(buff));
        printf("Enter msg:\n");
        fgets(buff, 1000, stdin);
        sendto(sd, buff, sizeof(buff), 0, (struct sockaddr*)&server, slen);
        printf("message sent!");
        bzero(&buff, sizeof(buff));
        recvfrom(sd, buff, sizeof(buff), 0, (struct sockaddr*)&server, &slen);
        printf("%s", buff);
    }
}
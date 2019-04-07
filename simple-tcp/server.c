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
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(2000);

    sd = socket(AF_INET, SOCK_STREAM, 0);

    bind(sd, (struct sockaddr *)&server, sizeof(server));

    listen(sd, 5);
    printf("server is runnning...\n");

    cd = accept(sd, (struct sockaddr*)&client, &clilen);

    while(1) {
        bzero(&buff, sizeof(buff));
        recv(cd, buff, sizeof(buff), 0);
        printf("Client: %s\n", buff);
    }
}

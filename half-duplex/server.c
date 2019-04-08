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
    char buff1[1000], buff2[1000];
    socklen_t clilen = sizeof(client);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(2000);

    sd = socket(AF_INET, SOCK_STREAM, 0);

    bind(sd, (struct sockaddr*)&server, sizeof(server));

    listen(sd, 5);

    cd = accept(sd, (struct sockaddr*)&client, &clilen);

    while(1) {
        bzero(&buff1, sizeof(buff1));
        bzero(&buff2, sizeof(buff2));
        recv(cd, buff1, sizeof(buff1), 0);
        printf("Client: %s", buff1);
        printf("\nEnter message: ");
        fgets(buff2, sizeof(buff2), stdin);
        send(cd, buff2, sizeof(buff2), 0);
    }
}
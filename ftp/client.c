#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdio.h>
#include<unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
int sd,cd;
struct sockaddr_in servaddr,cliaddr;
socklen_t clilen;
char buff[100],file[10000];
struct hostent *h;

bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
servaddr.sin_port=htons(1500);

sd=socket(AF_INET,SOCK_STREAM,0);
cd=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));


printf("%s\n","Enter the File Name :");
scanf("%s",buff);
send(sd,buff,strlen(buff)+1,0);
printf("%s\n","File Output :");
recv(sd,file,sizeof(file),0);
printf("%s",file);
close(sd);
return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#define PORT 8080
#define maxline 1024
int main(){
int sockfd;
char buffer[maxline];
char* hello="Hello from Client";
struct sockaddr_in servaddr;
if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0){
perror("socket generation");
exit(EXIT_FAILURE);
}
memset(&servaddr,0,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(PORT);
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
int n,len;
sendto(sockfd,(const char*)hello,strlen(hello),MSG_CONFIRM,(const struct sockaddr*)&servaddr,sizeof(servaddr));
printf("Hello message sent");
n=recvfrom(sockfd,(char*)buffer,maxline,MSG_WAITALL,(struct sockaddr*)&servaddr,&len);
buffer[n]='\0';
printf("Server: %s\n",buffer);
close(sockfd);
return 0;
}

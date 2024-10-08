#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
#define maxline 1024
int main(){
int sockfd;
char buffer[maxline];
char* hello="\nHello from Server\n";
struct sockaddr_in servaddr,cliaddr;
if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0){
perror("\nSocket Creation failed\n");
exit(EXIT_FAILURE);
}
memset(&servaddr,0,sizeof(servaddr));
memset(&cliaddr,0,sizeof(cliaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(PORT);
servaddr.sin_addr.s_addr=INADDR_ANY;
if(bind(sockfd,(const struct sockaddr*)&servaddr,sizeof(servaddr))<0){
perror("Bind failed");
exit(EXIT_FAILURE);
}
int len,n;
len=sizeof(cliaddr);
n=recvfrom(sockfd,(char*) buffer,maxline,MSG_WAITALL,(struct sockaddr*)&cliaddr,&len);
buffer[n]='\0';
printf("\n%s\n",buffer);
sendto(sockfd,(const char *)hello,strlen(hello),MSG_CONFIRM,(const struct sockaddr*)&cliaddr,len);
printf("\nHello message sent\n");
return 0;
}


# include<stdio.h>
# include<sys/socket.h>
# include<netinet/in.h>
# include<strings.h>
# include<string.h>

void send_soc(int sockfd,char * buf);
void recv_soc(int sockfd,char * buf);
int flag = 2;
int main(int argc,char **argv)
{
 int i,j,l,sockfd,clilen,newsockfd,n;
char buf[4096],buf1[4096];

struct sockaddr_in servaddr,cliaddr;
sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(8082);
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

bind(sockfd,(struct aockaddr *)&servaddr,sizeof(servaddr));
listen(sockfd,5);
clilen=sizeof(cliaddr);
newsockfd=accept(sockfd,(struct sockaddr *) &cliaddr,&clilen);
    printf("------------------------------------------------------\n");

    printf("Connection Established with Client \n");

    printf("-------------WELCOME TO COMMAND CHATTING----------------------\n");
while (1) {
if (flag == 1)	
{
fgets(buf,256,stdin);
write(newsockfd,buf,strlen(buf));
send_soc(newsockfd,&buf);
}
if (flag == 2)
{
recv_soc(newsockfd,&buf1);	
}
}
close(newsockfd);
}

void send_soc(int newsockfd,char * buf)
{
send(newsockfd,&buf, strlen(buf),0);
printf("You-: %s", buf);
flag =2;
}

void recv_soc(int newsockfd,char * buf1)
{
recv(newsockfd, buf1, sizeof(buf1),0);	
printf("Him-: %s", buf1);
flag =1;
}

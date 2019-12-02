# include<stdio.h>
# include<sys/socket.h>
# include<netinet/in.h>
# include<strings.h>
# include<string.h>
// Global Data
void send_soc(int sockfd,char * buf);
void recv_soc(int sockfd,char * buf);
 int flag = 2;

int main(int argc,char **argv)
{
 int sockfd,n;
char buf[4096];  
char buf2[4096];  

struct sockaddr_in cliaddr;
sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
bzero(&cliaddr,sizeof(cliaddr));
cliaddr.sin_family=AF_INET;
cliaddr.sin_port=htons(8082);
//cliaddr.sin_addr.s_addr=htonl(INADDR_ANY);
inet_pton(AF_INET, argv[1], &cliaddr.sin_addr);
connect(sockfd,(struct sockaddr *) &cliaddr,sizeof(cliaddr));
    printf("------------------------------------------------------\n");

    printf("Connection Established \n");

    printf("-------------WELCOME TO COMMAND CHATTING----------------------\n");
    
while (1) {
if (flag == 2)	
{
memset(buf , 0 , sizeof(buf));	
fgets(buf,256,stdin);
write(sockfd,buf,strlen(buf));
send_soc(sockfd,&buf);
}
if (flag == 1)
{
recv_soc(sockfd,&buf2);	
}
}
close(sockfd);
}

void send_soc(int sockfd,char * buf)
{
send(sockfd,&buf,strlen(buf),0);
printf("You-: %s", buf);
flag =1;
}

void recv_soc(int sockfd,char * buf2)
{
recv(sockfd, buf2, sizeof(buf2),0);
printf("Him-: %s", buf2);
flag =2;
}

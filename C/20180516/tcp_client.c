#include "fun.h"
#include <crypt.h>
int main(int argc, char**argv){
  int client_sockfd;
  int server_sockid;
  int len;
  struct sockaddr_in remote_addr;
  char buf[BUFSIZ];
  char buf2[BUFSIZ];
  memset(&remote_addr,0,sizeof(remote_addr)); //数据初始化--清零  
  remote_addr.sin_family=AF_INET; //设置为IP通信  
  remote_addr.sin_addr.s_addr=inet_addr("127.0.0.1");//服务器IP地址  
  remote_addr.sin_port=htons(7777); //服务器端口号  

  if((client_sockfd=socket(AF_INET,SOCK_STREAM,0))<0)  
  {  
    perror("socket error");  
    return 1;  
  }  
  if(connect(client_sockfd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr))<0)
  {
    perror("connect error");
    return 1;
  }
  printf("connected to server\n");
  len=recv(client_sockfd,buf,BUFSIZ,0);//接收服务器端信息
  buf[len]='\0';
  printf("%s",buf); //打印服务器端信息
  fd_set fdset;
  while(1)
  { FD_ZERO(&fdset);
    FD_SET(STDIN_FILENO,&fdset);
    FD_SET(client_sockfd,&fdset);
    printf("username\n");
    int ret = select(client_sockfd+1,&fdset,NULL,NULL,NULL);
    if(ret>0){
    if(FD_ISSET(client_sockfd,&fdset)){
      bzero(buf, sizeof(buf));
      ret = recv(client_sockfd, buf, sizeof(buf),0);
      if(ret == 0){
        printf("ByeBye\n");
        break;
      }else
        printf("Received:%s\n", buf);
    }
    if(FD_ISSET(0,&fdset)){
    
    bzero(buf, sizeof(buf));
    bzero(buf2, sizeof(buf2));
    ret = read(STDIN_FILENO, buf, sizeof(buf)-1);
     if(ret == 0) {
      printf("Bye\n");
      break;
    }
    printf("password\n");
    ret = read(STDIN_FILENO, buf2, sizeof(buf2)-1);
    if(ret == 0) {
      printf("Bye\n");
      break;
    }
    char * cpwd =(char*) calloc(1,44);
    cpwd = crypt(buf2, "$5$elephant");
    
   // if(!strcmp(buf,"quit")){
   //   break;
   // }
    len=send(client_sockfd,buf,strlen(buf)-1,0);  
    len=send(client_sockfd,cpwd,strlen(cpwd),0);  
  //  len=recv(client_sockfd,buf,BUFSIZ,0); 
  //  buf[len] = '\0';
  //  printf("reveived: %s\n",buf);
  }
  }}
  close(client_sockfd);
  return 0;

}

#include "fun.h"

int main(int argc, char**argv){
  int server_sockfd;//服务端sc
  int client_sockfd;//客户端sc
  int len;
  struct sockaddr_in my_addr;//服务器网络地址结构体
  struct sockaddr_in remote_addr;//客户端网络地址结构体
  socklen_t sin_size;
  char buf[BUFSIZ];
  memset(&my_addr,0,sizeof(my_addr));
  my_addr.sin_family = AF_INET;//ipv4
  my_addr.sin_addr.s_addr = INADDR_ANY;//0.0.0.0
  my_addr.sin_port = htons(7777);
  if((server_sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
    perror("server socket error");
    return -1;
  }

  //bind
  if(bind(server_sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))<0){
    perror("s bind error");
    return -1;
  }

  //listen
  int listen_ret;
  if((listen_ret = listen(server_sockfd,15))<0){
    perror("listen error");
    return -1;}
  sin_size = sizeof(struct sockaddr_in);
  int ret = 0;
  fd_set fdset; 
  fd_set tmpset;
  FD_ZERO(&tmpset);
  FD_SET(0,&tmpset);
  FD_SET(server_sockfd,&tmpset);
  //wait client
  int select_r;
    printf("waitting\n");
  while(1){
    FD_ZERO(&fdset);
    memcpy(&fdset, &tmpset,sizeof(fd_set));
    select_r = select(15,&fdset,NULL,NULL,NULL);
    if(select_r >0){
      if(FD_ISSET(server_sockfd, &fdset)){
        pid_t child;
        client_sockfd = accept(server_sockfd, (struct sockaddr*)&remote_addr,&sin_size);
    //    if((child = fork())==0){
        printf("\n");
        if(client_sockfd <0) {
          perror("server accept error");
          return -1;
        }
        FD_SET(client_sockfd,&tmpset);
        printf("accept client %s\n", inet_ntoa(remote_addr.sin_addr));
        len = send(client_sockfd, "Welcome!\n",21,0); }
     //   else {  
    //    FD_SET(client_sockfd,&tmpset);
    //      close(client_sockfd); }
    //  }
      //receive client data
      if(FD_ISSET(client_sockfd,&fdset)){
        bzero(buf,sizeof(buf));
        len = recv(client_sockfd,buf,BUFSIZ,0);
        buf[len] = '\0';

        if(len == 0){
          printf("Bye\n");
          FD_CLR(client_sockfd,&tmpset);
          close(client_sockfd);
        }else{ 
          printf("Received:%s\n",buf);
        }
      }
      if(FD_ISSET(0,&fdset)) {
        bzero(buf,sizeof(buf));
        ret = read(STDIN_FILENO,buf,sizeof(buf)-1);
        if(ret == 0){
          printf("Bye\n");
          FD_CLR(client_sockfd,&fdset);
          close(client_sockfd);
        }
        printf("message sent!\n");
        send(client_sockfd,buf,strlen(buf)-1,0);
      }
    }
  }


    close(server_sockfd);
}

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
  int epfd = epoll_create(2);//create epoll
  struct epoll_event event, evs[3];//里面2个东西 第一个是事件 比如读写 第二个是数据
  event.events = EPOLLIN;//可读
  event.data.fd = 0;
  ret = epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &event);//epfd/操作/data.fd/epoll_event
  if(ret == -1) {
    perror("epoll_ctl");
    return -1;
  }
  event.events = EPOLLIN;
  event.data.fd = server_sockfd;
  ret = epoll_ctl(epfd, EPOLL_CTL_ADD, server_sockfd, &event);
  int i, ret1;

  //wait client
  printf("waitting\n");
  while(1){
    ret1 = epoll_wait(epfd, evs, 3, -1);//最后2个是最大事件和超时时间
    for(i = 0;i < ret1; i++ ){
      printf("evs[i].data.fd = %d, i = %d\n",evs[i].data.fd, i);
      if(evs[i].data.fd == server_sockfd) { //可读
        len = sizeof(struct sockaddr);
        client_sockfd = accept(server_sockfd, (struct sockaddr*)&remote_addr,&sin_size);
        //    if((child = fork())==0){
        printf("\n");
        if(client_sockfd <0) {
          perror("server accept error");
          return -1;
        }
        event.events = EPOLLIN;
        event.data.fd = client_sockfd;
        epoll_ctl(epfd, EPOLL_CTL_ADD, client_sockfd, &event);
        printf("accept client %s\n", inet_ntoa(remote_addr.sin_addr));
        len = send(client_sockfd, "Welcome!\n",21,0); 
        printf("Client ip%s : port%d\n", inet_ntoa(remote_addr.sin_addr),ntohs(remote_addr.sin_port));
      }
      //   else {  
      //    FD_SET(client_sockfd,&tmpset);
      //      close(client_sockfd); }
      //  }
      //receive client data
      if(evs[i].data.fd == client_sockfd){
        bzero(buf,sizeof(buf));
        len = recv(client_sockfd,buf,BUFSIZ,0);
        buf[len] = '\0';

        if(len == 0){
          printf("Bye\n");
          event.events = EPOLLIN;
          event.data.fd = client_sockfd;
          epoll_ctl(epfd, EPOLL_CTL_DEL, client_sockfd, &event);
          close(client_sockfd);
        }else{ 
          printf("Received:%s\n",buf);
        }
      }
      if(evs[i].data.fd == 0) {
        bzero(buf,sizeof(buf));
        ret = read(STDIN_FILENO,buf,sizeof(buf)-1);
        if(ret == 0){
          printf("Bye\n");
          event.events = EPOLLIN;
          event.data.fd = client_sockfd;
          epoll_ctl(epfd, EPOLL_CTL_DEL, client_sockfd, &event);
          close(client_sockfd);
        }
        printf("message sent!\n");
        send(client_sockfd,buf,strlen(buf)-1,0);
      }
    }
  }

  close(server_sockfd);
}

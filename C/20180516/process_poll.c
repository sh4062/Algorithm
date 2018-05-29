#include "fun.h"

typedef struct {
  pid_t pid;
  int fd;
  short busy;
}Data, *pData;

void child_handle(int fd){
  char flag;
  while(1){
    read(fd, &flag, 1);
    sleep(3);
    printf("send successfully! \n");
    write(fd, &flag, 1);
  }
}

void make_child(pData p, int n) {
  //产生子进程
  int i;
  int fds[2];
  int ret;
  pid_t pid;
  for (i = 0; i < n; i++) {
    ret = socketpair(AF_LOCAL, SOCK_STREAM, 0, fds);//产生一对sockets
    if(ret == -1){
      perror("socketpair");
      return;
    }
    pid = fork();
    if(pid == 0){
      close(fds[1]);
      child_handle(fds[0]);
    }
    close(fds[0]);
    p[i].pid = pid;
    p[i].fd = fds[1];
  }

}

int main(int argc, char* argv[]){
  if(argc != 4) {
    printf("Wrong Args");
    return -1; 
  }
  int pro_num = atoi(argv[3]);//n个子进程
  pData p = (pData)calloc(pro_num, sizeof(Data));
  make_child(p, pro_num);
  int sfd = socket(AF_INET, SOCK_STREAM,0);
  if(sfd == -1) {
    perror("server socket");
    return -1;
  }
  int reuse = 1;
  int ret = setsockopt(sfd,SOL_SOCKET, SO_REUSEADDR,(const char*)&reuse,sizeof(int) );//设置重用
  if(ret == -1) {
    perror("server setsockopt");
    return -1;
  }
  struct sockaddr_in ser;
  bzero(&ser,sizeof(ser));
  ser.sin_family = AF_INET;
  ser.sin_port = htons(atoi(argv[2]));
  ser.sin_addr.s_addr = inet_addr(argv[1]);
  ret = bind(sfd, (struct sockaddr*)&ser,sizeof(struct sockaddr));
  if(ret == -1){
    perror("bind");
    return -1;
  }
  int epfd = epoll_create(1);
  struct epoll_event event,*evs;
  evs = (struct epoll_event*)calloc(pro_num + 1, sizeof(event));
  event.events = EPOLLIN;
  event.data.fd = sfd;
  epoll_ctl(epfd, EPOLL_CTL_ADD, sfd, &event);
  int i, j;
  for(i = 0; i < pro_num; i++) {
    event.data.fd = p[i].fd;
    epoll_ctl(epfd, EPOLL_CTL_ADD, p[i].fd, &event);
  }
  ret = listen(sfd, 10);
  if(ret == -1) {
    perror("listen");
    return -1;
  }
  int rnum;
  int cfd;
  struct sockaddr_in client;
  char flag;
  socklen_t len;
  printf("Waitting!\n");
  while(1) {
    rnum = epoll_wait(epfd,evs,pro_num + 1,-1);//epfd/*events/maxevenrs/timeout
    for(i = 0; i<rnum;i++) {
      if(sfd == evs[i].data.fd) {
        len = sizeof(struct sockaddr);
        cfd = accept(sfd,(struct sockaddr*)&client,&len);
        printf("client ip = %s, port = %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
        len = send(cfd,"Welcome\n",10,0);
        for(j = 0;j < pro_num; j++) {
          if(p[j].busy == 0) {
            write(p[j].fd,&cfd, 1);
            p[j].busy = 1;
            printf("%d is busy\n",p[j].pid);
            break;
          }
        }
      }
      //
      for(j = 0;j < pro_num; j++) {
        if(p[j].fd == evs[i].data.fd) {
          read(p[j].fd,&flag, 1);
          p[j].busy = 0;
          printf("%d is not busy\n",p[j].pid);
        }
      }
    }
  }
}

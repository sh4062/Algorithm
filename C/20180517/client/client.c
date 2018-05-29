#include "func.h"

int recv_n(int sfd, char*p, int len){
  int ret;
  int total = 0;
  while(total < len) {
    ret = recv(sfd, p + total, len-total,0);
    total += ret;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  if(argc != 3) {
    printf("Wrong Args");
    return -1;
  }
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(server_fd == -1) {
    perror("server_fd");
    return -1;
  }
  struct sockaddr_in server;
  bzero(&server, sizeof(server));
  server.sin_addr.s_addr = inet_addr(argv[1]);
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  int ret = connect(server_fd, (struct sockaddr *)&server, sizeof(struct sockaddr));
  if(ret == -1){
    perror("connect");
    return -1;
  }
  char buf[1111] = {0};
  int len;
  // receive file name
  recv(server_fd, &len, sizeof(int), 0);
  recv(server_fd, buf, len, 0);
  int fd = open(buf, O_RDWR|O_CREAT,0666);
  if(fd == -1) {
    perror("file open");
    return -1;
  }
  //receive file
  while(1){
    recv_n(server_fd,(char*)&len,sizeof(int));
    if(len>0)
    {
      recv_n(server_fd,buf,len);
      write(fd,buf,len);
    }else{
      printf("file recv success\n");
      break;
    }
  }
  close(fd);
  return 0;
}

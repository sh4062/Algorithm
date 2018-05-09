#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char** argv){
  if(argc!=2){
    printf("Error Args!");
    return -1;
  }
  int fd;//文件描述符
  fd = open(argv[1],O_RDWR);
  if(fd == -1){
  perror("Open");
  return -1;
  }
  char buf[15] = {0};
  while(memset(buf,0,sizeof(buf)), read(fd, buf, sizeof(buf)-1 ) > 0){
    printf("%s", buf);
  }
  close(fd);
  return -1;

}

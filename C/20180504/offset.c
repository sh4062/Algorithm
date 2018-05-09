#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
  int fd = open("./fd.c", O_RDONLY);
  printf("fd = %d\n",fd);
  lseek(fd,1,SEEK_SET);
  char buf[30]={0};
  int fr = read(fd, buf, sizeof(buf)-1);
  printf("buf = %s,%d",buf,fr);
  close(fd);
  return 0;
}

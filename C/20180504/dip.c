#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(){
  char buf[32] ={0};
  int fd1 = open("1.data",O_RDWR);
  read(fd1,buf,8);
  puts(buf);
 // close(fd1);
 // int fd2 = dup(fd1);
  close(1);
  int fd2 = dup(fd1);
  lseek(fd2,0,SEEK_SET);
  memset(buf,0,8);
  read(fd2,buf,sizeof(buf)-1);
   puts(buf) ;
   lseek(fd2,0,SEEK_END);
  printf("asdasdasd==========%d",fd2);
  close(fd2);
}


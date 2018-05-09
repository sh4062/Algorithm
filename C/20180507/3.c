#include "fun.h"
int main(){
  printf("%d\n",getpid());
  int fd = open("file", O_RDWR);
  pid_t pid;
  pid = fork();
  if(pid == 0){
    printf("I am child %d",getpid);
  write(fd,"WOCAO",6);
  } else{ int ret = lseek(fd,5,SEEK_CUR);
  }
  close(fd);

}

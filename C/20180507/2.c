#include "fun.h"

int main(){
  printf("uid = %d,gid = %d, euid = %d,egid = %d",
      getuid(),getgid(),geteuid(),getegid());

  int fd = open("a",O_RDWR);
  if(fd == -1){
    perror("open");
    return -1;
  }
  write(fd,"???????????????",50);
  close(fd);
  return 0;

}

#include "fun.h"

int main(){
  int fds[2] = {0};
  pipe(fds);
  char szBuf[32] = {'\0'};
  pid_t chd = fork();
  if(chd == 0){
    close(fds[1]);
    sleep(2);
    if(read(fds[0],szBuf,sizeof(szBuf))>0){
      puts(szBuf);
    }
    close(fds[0]);
    exit(0);
  } else{
    close(fds[0]);
    write(fds[1], "asdaszxcewradcxzc",25);
    waitpid(-1, NULL, 0);

    close(fds[1]);
    exit(0);
  
  
  }
  return 0;
}

#include "fun.h"

int main(){
  pid_t d;
  d = fork();
  if(d == -1)
  {
    return -1;
  }
  else if(d != 0){ //父进程调用exit,保证子进程不是进程组长
    exit(EXIT_SUCCESS);
  }
  setsid();
  chdir("./");
  umask(0);
  while(1){
    sleep(5);
    syslog(LOG_INFO, "This is a log");
  }

}

#include "fun.h"//孤儿的父进程不是1 因为ubuntu用systemd代替init
#include<signal.h>
int main(){
  //pid_t pid= fork();
  //  if(pid == 0){
  //    while(1);
  //  }
  //  else{
  //    exit(0);
  //  }
  pid_t pid ;
  signal(SIGCHLD,SIG_IGN);
  printf("before fork pid:%d\n",getpid());
  int abc = 10;
  pid = fork();
  if(pid == -1)
  {
    perror("tile");
    return -1;
  }
  if(pid > 0)           //父进程先退出
  {
    abc++;
    printf("parent:pid:%d \n",getpid());
    printf("abc:%d \n",abc);
    sleep(5);
  }
  else if(pid == 0){  //值进程后退出,被托付给init进程
    abc++;
    printf("child:%d,parent: %d\n",getpid(),getppid());
    printf("abc:%d",abc);
    sleep(100);
  }
  printf("fork after...\n");
}

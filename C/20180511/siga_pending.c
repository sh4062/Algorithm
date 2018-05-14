#include "fun.h"

void sig_handler(int signum, siginfo_t *p, void * p1){
  printf("before sleep signal is comming %d\n", signum);
  sleep(5);
  sigset_t pend;
  sigpending(&pend);
  if(sigismember(&pend, SIGINT)){
    printf("SIGINT is pending\n");
  }
  else{
    printf("SIGINT is not pending\n");
  }
  printf("after sleep signal is comming %d\n", signum);

  
}
int main(){
  struct sigaction act;
  memset(&act, 0, sizeof(act));
  act.sa_sigaction = sig_handler;
  act.sa_flags = SA_SIGINFO;
  sigemptyset(&act.sa_mask);
  sigaddset(&act. sa_mask, SIGQUIT);
  int ret = sigaction(SIGINT, &act, NULL);
  if(ret == -1){
    perror("???");
    return -1;
  }
  //sigaction(SIGQUIT, &act, NULL);
  while(1);
  return 0;
}

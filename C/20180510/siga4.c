#include<signal.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
int cnt = 0;
void handleS(int signo, siginfo_t * p, void *p1){
  cnt++;
  printf("Before,cnt:%d Sigo: %d\n",cnt,signo);
  sleep(3);
  printf("After,cnt: %d Sigo: %d\n",cnt,signo);
}

int main(){
  struct sigaction act;
  sigemptyset(&act.sa_mask);
sigaddset(&act.sa_mask,SIGQUIT);
// struct sigaction st;
 act.sa_sigaction = handleS;

 act.sa_flags = SA_SIGINFO|SA_NODEFER;
 int ret =sigaction(SIGINT, &act, NULL);
 if(ret == -1){
   perror("asdzxcqwezxcSIG");
   return -1;
 }
 sigaction(SIGQUIT,&act, NULL);
 while(1);
 return 0;
}

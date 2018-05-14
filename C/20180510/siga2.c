#include<signal.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
int cnt = 0;
void handleS(int signo, siginfo_t * p, void *p1){
  cnt++;
  printf("Before,cnt:%d Sigo: %d\n",cnt,signo);
  sleep(1);
  printf("After,cnt: %d Sigo: %d\n",cnt,signo);
}

int main(){
 struct sigaction st;
 st.sa_sigaction = handleS;
 st.sa_flags = SA_SIGINFO;
 int ret =sigaction(SIGINT, &st, NULL);
 if(ret == -1){
   perror("asdzxcqwezxcSIG");
   return -1;
 }
 sigaction(SIGQUIT,&st, NULL);
 while(1);
 return 0;
}

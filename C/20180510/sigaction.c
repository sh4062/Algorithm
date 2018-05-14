#include<signal.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void handleS(int signo){
  printf("Before, Sigo: %d\n",signo);
  sleep(1);
  printf("After, Sigo: %d\n",signo);
}

int main(){
 printf("capture sig\n");
 struct sigaction st;
 //memset(&st,0,sizeof(st));
// st.sa_handler = handleS;
// st.sa_flags = 0;
// int ret = sigaction(SIGINT, &st, NULL);
// if(ret == -1){
//   printf("????");
// }
 while(1);
 return 0;
}

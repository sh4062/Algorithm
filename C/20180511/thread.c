#include "fun.h"

void* thfun(void*p){
  printf("I am thread????????????????I receive %d\n",(int)p);
//  rhile(1);
pthread_exit((void *)(2)); 
}

int main(){
  pthread_t thid;
  int ret = pthread_create(&thid, NULL, thfun, (void*)1);
  int rec = 0;
  if(ret != 0){
    printf("??????????????");
    return -1;
  }
  sleep(1);
  pthread_join(thid,(void **)&rec);
  printf("Main  receive: %d\n",rec);
  return 0;

}

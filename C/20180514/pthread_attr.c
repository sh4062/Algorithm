#include "fun.h"

typedef struct {
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} pmc;

void * t1 (void *p){
  int ret;
  printf("I am child thread,%d\n",(int)pthread_self());
  pthread_exit(NULL);
}

int main (){
  pmc t;
  pthread_t tn1;
  pthread_create(&tn1, NULL, t1,&t);
  int ret =  pthread_detach(tn1);
  if(ret != 0){
    printf("detach error\n");
      return -1;
  }
   ret = pthread_join(tn1, NULL);
  printf("wait success %d\n",ret);
  return 0;
}




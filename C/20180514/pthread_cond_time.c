#include "fun.h"

typedef struct {
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} pmc;

void * t1 (void *p){
  pmc*t = (pmc*)p;
  int ret;
  printf("I am child thread, waitting\n");
  struct timespec t1;
  memset(&t1, 0 ,sizeof(t1));
  t1.tv_sec =  + 4;
 // t1.tv_sec = time(NULL) + 4;
  pthread_mutex_lock(&t -> mutex);
  ret = pthread_cond_timedwait(&t ->cond, &t->mutex,&t1);
  pthread_mutex_unlock(&t -> mutex);
  printf("I am child thread, wake up, ret = %d\n",ret);
  pthread_exit(NULL);
}

int main (){
  pmc t;
  pthread_mutex_init(&t.mutex,NULL);
  int ret = pthread_cond_init(&t.cond, NULL);
  if(ret != 0){
    printf("cond init error");
      return -1;
  }
  pthread_t tn1;
  pthread_create(&tn1, NULL, t1,&t);
  sleep(1);
  pthread_cond_signal(&t.cond);
  pthread_join(tn1, NULL);
  printf("wait success");
  return 0;
}




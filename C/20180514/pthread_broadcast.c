#include "fun.h"

typedef struct {
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} pmc;

void * t1 (void *p){
  pmc*t = (pmc*)p;
  int ret;
  printf("I am child thread%u, waitting\n", (unsigned int) pthread_self());
  struct timespec t1;
  memset(&t1, 0 ,sizeof(t1));
  t1.tv_sec = time(NULL) + 4;
  pthread_mutex_lock(&t -> mutex);
  ret = pthread_cond_wait(&t ->cond, &t->mutex);
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
  pthread_t tn1,tn2;
  pthread_create(&tn1, NULL, t1,&t);
  pthread_create(&tn2, NULL, t1,&t);
  sleep(1);
 // pthread_cond_signal(&t.cond);
  pthread_cond_broadcast(&t.cond);
  pthread_join(tn1, NULL);
  pthread_join(tn2,NULL);
  printf("wait success");
  return 0;
}




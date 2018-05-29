#include "factory.h"
//Init all elements in factory
void factory_init(factory *p, int num, int capcity) {
  bzero(p, sizeof(factory));
  p->pth = (pthread_t*)calloc(num, sizeof(pthread_t));
  pthread_cond_init(&p->cond, NULL);
  p->pthread_num = num;
  p->que.que_capcity = capcity;
  pthread_mutex_init(&p->que.que_mutex, NULL);
}
//start thread
void factory_start(factory*p) {
  int i;
  if(!p->start_flag) {
    for(i = 0; i < p->pthread_num; i++) {
      int r = pthread_create(p->pth + i, NULL, threadfunc, p);
      if(r != 0) {
        printf("ERROR CREATE THREAD!");
        exit(10);
      }
    }
    p->start_flag = 1;
  }

}
//thread
void *threadfunc(void *p) {
  factory *pf = (factory*)p;
  pque_t pq = &pf->que;
  pnode_t pcur;
  while(1) {
    pthread_mutex_lock(&pq->que_mutex);
    if(!pq->que_size){
      pthread_cond_wait(&pf->cond, &pq->que_mutex);
    }
    que_get(pq, &pcur);
    pthread_mutex_unlock(&pq->que_mutex);
    printf("Trans\n");
    trans_file(pcur->new_fd);
    free(pcur);
  }
  return NULL;
}



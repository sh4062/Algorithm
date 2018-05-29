#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "head.h"
#include "work_que.h"

typedef struct {
  pthread_t *pth;
  pthread_cond_t cond;
  que_t que;
  int pthread_num;
  short start_flag;
}factory;

void factory_init(factory*, int,int);
void factory_start(factory*);
void * threadfunc(void*);
void trans_file(int);
int send_n(int, char*, int);
typedef struct {
  int len;
  char buf[1111];
}train;
#define FILENAME "file"
#endif

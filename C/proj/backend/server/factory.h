#ifndef __FACTORY_H__
#define __FACTORY_H__
#include "head.h"
#include "work_que.h"
#include "sql.h"
#include "utils.h"
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
typedef struct {
  int len;
  char buf[1024];
}train;
#define FILENAME "file"
#endif

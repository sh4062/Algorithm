#ifndef __WORK_QUE_H__
#define __WORK_QUE_H__
#include "head.h"
typedef struct  tag_node{
  int new_fd;
  struct tag_node* pnext;
} node_t, *pnode_t;

typedef struct {
 pnode_t head, tail;
 int que_capcity;
 int que_size;
 pthread_mutex_t que_mutex;
  
}que_t, *pque_t;

void que_insert(pque_t, pnode_t);
void que_get(pque_t, pnode_t*);
#endif

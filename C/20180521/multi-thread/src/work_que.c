#include "work_que.h"

void que_insert(pque_t pq, pnode_t pnew) {
  if(!pq->head) {
    pq->head = pnew;
    pq->tail = pnew;
  }
  else {
    pq->tail->pnext = pnew;
    pq->tail = pnew;
  }
  pq->que_size++;
}

void que_get(pque_t pq, pnode_t* p) {
  *p = pq->head;
  pq->head = pq->head->pnext;
  pq->que_size--;

}

//int main(){
//  return 0;
//}

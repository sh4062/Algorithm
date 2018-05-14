#include "fun.h"
#include <pthread.h>
int count = 0;
pthread_mutex_t lock;
void *salewinds1(void *args)
{  int i = 1000000;
    while (i--)
    {
        pthread_mutex_lock(&lock); //因为要访问全局的共享变量， 所以就要加锁
        count++;
        pthread_mutex_unlock(&lock); //解锁
        //sleep(1);                    //要放到锁的外面， 让另一个有时间锁
    }
}
void *salewinds2(void *args)
{   int i = 1000000;
    while (i--)
    {
        pthread_mutex_lock(&lock); //因为要访问全局的共享变量， 所以就要加锁
        count++;
        pthread_mutex_unlock(&lock); //解锁
        //sleep(1);                       //要放到锁的外面， 让另一个有时间锁
    }
}
int main()
{
    pthread_t pthid1 = 0;
    pthread_t pthid2 = 0;
    pthread_mutex_init(&lock, NULL);                 //初始化锁
    pthread_create(&pthid1, NULL, salewinds1, NULL); //线程 1
    pthread_create(&pthid2, NULL, salewinds2, NULL); //线程 2
    printf("RESULT: %d\n",count);
    pthread_join(pthid1, NULL);
     
    pthread_join(pthid2, NULL);
    pthread_mutex_destroy(&lock); //销毁锁
    printf("RESULT: %d",count);
    return 0;
}
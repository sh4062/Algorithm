#include "fun.h"

void clean(void *p)
{
    free(p);
    printf("free!");
}

void * thread1(void *p)
{
    p = malloc(111);
    pthread_cleanup_push(clean, p);
    printf("thread1 sleep!");
    sleep(6);
    printf("thread1 wake up!");
    pthread_exit(NULL);
    pthread_cleanup_pop(1);
}

int main(){
    pthread_t t1;
    pthread_create(&t1,NULL,thread1,NULL);
    int res = pthread_cancel(t1);
    if(res !=0){
        printf("cancal failed!");
        return -1;
    }
    long l;
    pthread_join(t1,(void**)&l);
    printf("main!");
    return 0;
    }
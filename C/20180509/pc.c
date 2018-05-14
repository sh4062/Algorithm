#include "fun.h"

union semun{
  int val;
  struct semid_ds *buf;
  unsigned short* array;
};
int main(){
  int semid = semget(IPC_PRIVATE,1,0666|IPC_CREAT);
  if(semid == 1){
    perror("semget");
    return -1;
  }
  if(fork()==0){
    printf("child");
    struct sembuf sem;
    memset(&sem, 0, sizeof(struct sembuf));
    sem.sem_num = 0;
    sem.sem_op = 1;
    sem.sem_flg = 0;
    union semun arg;
    arg.val = 0;
    semctl(semid,0,SETALL,arg);
    printf("aaaaaaaaaaaaaaaaaaaa");
    while(1){
      semop(semid, &sem, 1);
      printf("produce, product total num: %d", semctl(semid,0,GETVAL));
      sleep(1);
    }
  }
  else

  {

    sleep(2); //先让子进程有时间生产

    struct sembuf sem; //定义信号量结构体

    memset(&sem, 0, sizeof(struct sembuf));

    sem.sem_num = 0; //信号量的编号,第一个为 0

    sem.sem_op = -1; //-1 表示执行 P 操作,消费产品

    sem.sem_flg = 0; //或写 SEM_UNDO

    while(1)

    {

      semop(semid, &sem, 1);//执行指定的 P 操作消费产品

      printf("costomer total number:%d\n", semctl(semid, 0, GETVAL));//获得公

      

        sleep(5);

    }

  }

}


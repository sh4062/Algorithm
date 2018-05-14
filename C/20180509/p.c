#include "fun.h"
int semid;
void delsem(){
  semctl(semid,IPC_RMID,0);
}
int main(){
  union semun{
    int val; /* Value for SETVAL */
    struct semid_ds *buf; /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
  }semun;
  semid = semget((key_t)1111,2,IPC_CREAT);
  if(semid == -1){
    perror("semget");
    return -1;
  }
  unsigned short semarray[2] = {0,10};
  semun.array = semarray;
  int ret = semctl(semid, 0, SETALL, semun);
  if(ret == -1){
    perror("semclt");
    return -1;
  }
  printf("productor init is %d\n", semctl(semid, 0, GETVAL));
  printf("space init is %d\n", semctl(semid, 1, GETVAL));
  struct sembuf sembuf[2];//这个是信号操作的buffer 里面记录信号op
  sembuf[0].sem_num = 0;
  sembuf[0].sem_op = 1;
  sembuf[0].sem_flg = 0;
  sembuf[1].sem_num = 1;
  sembuf[1].sem_op = -1;
  sembuf[1].sem_flg = 0;

  while(1){
    printf("\nBefore produce, pnum = %d, snum = %d; \n",semctl(semid,0,GETVAL),semctl(semid, 1, GETVAL));
    //P space
    semop(semid, (struct sembuf*)&sembuf[1],1);
    printf("+1s");
    //V full
    semop(semid,(struct sembuf *) &sembuf[0],1);

    printf("\nAfter produce, pnum = %d, snum = %d; \n",semctl(semid,0,GETVAL),semctl(semid, 1, GETVAL));
    sleep(2);

  
  }delsem();
}

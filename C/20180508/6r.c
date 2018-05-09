#include "fun.h"

int main(){
  key_t key = ftok ("./key.key", 1);
  if(key == -1){
    perror("ftok");
    exit(-1);
  }

  int shmid = shmget(key, 4096,IPC_CREAT);
  if(shmid == -1){
    perror("shmid");
    exit (-1);
  }

  char * pm =( char*) shmat (shmid, NULL,0);
  printf("shared memory:\n  %s",pm);
  if(shmctl(shmid, IPC_RMID,0)==-1){
    perror("shmctl");
    exit(-1);
  }
}

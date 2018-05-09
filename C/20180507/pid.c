#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
  pid_t getpid(void);
  pid_t  getppid(void);
  printf("p = %d, pp = %d", getpid, getppid);
}

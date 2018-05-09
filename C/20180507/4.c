#include "fun.h"
int main(){
  pid_t pid;
  pid = fork();
  if(pid == 0)
  execl("./add.o","add.o","1","2",NULL);
  printf(">?????");
  return 0;
  
}

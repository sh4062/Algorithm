#include "fun.h"

int main(){
  printf("uid: %d, gid: %d, euid: %d, egid: %d",getuid(), getgid(), geteuid(), getegid());
  return 0;
}//e 代表有效

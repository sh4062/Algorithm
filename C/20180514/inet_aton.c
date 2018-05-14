#include "fun.h"

int main(int argc, char**argv){
  if(argc != 2){
    perror("error args");
    return -1;
  }
  struct in_addr addr;
  int ret = inet_aton(argv[1], &addr);
  printf("%x\n", addr.s_addr);
  printf("0000000000000000000");
  printf("\n%x",inet_addr(argv[1]));
  return 0;
}

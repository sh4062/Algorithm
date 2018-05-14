#include "fun.h"

int main(int argc, char**argv){
  if(argc != 2){
    perror("error args");
    return -1;
  }

  short port = atoi (argv[1]);
  short nport;
  nport = htons(port);
  printf("%d\n", nport);
  printf("0000000000000000000");
  printf("\n%d",ntohs(nport));
  return 0;
}

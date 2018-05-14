#include "fun.h"

int main(int argc, char**argv){
  if(argc != 2){
    printf("wrong args");
      return -1;
  }
  struct hostent *p;
  p = gethostbyname(argv[1]);
  printf("host name: %s\n",p->h_name);
  int i =0;
  for(i; p->h_aliases[i]!=NULL;i++){
    printf("alias: %s\n",p->h_aliases[i]);
  }
  printf("length,%d\n",p->h_length);
  char c[16];
  for(i = 0;p-> h_addr_list[i]!=NULL;i++){
    memset(&c,0,16);
    inet_ntop(p->h_addrtype,p->h_addr_list[i],c,16);
    printf("ip:%s\n",c);
  }
  
}

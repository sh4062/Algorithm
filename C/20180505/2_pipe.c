#include "fun.h"

int main(int argc,char **argv){
  if(3 != argc) {
    printf("Error Args");
    return -1;
  }
  int fdw = open(argv[1],O_WRONLY);
  int fdr = open(argv[2],O_RDONLY);
  if( (-1 == fdr) || (-1 == fdw) )
  {

    perror("open");

    exit(-1);

  }
  printf("R %d W %d\n",fdr,fdw);
  char buf[128] = {0};
  int ret = 0;
  fd_set redset;
  while(1){
    FD_ZERO(&redset);
    FD_SET(0, &redset);
    FD_SET(fdr, &redset);
    ret = select(fdr + 1, &redset, NULL, NULL, NULL);
    if (ret > 0){
      if(FD_ISSET(fdr,&redset)) {
        memset(buf, 0, sizeof(buf));
        ret = read(fdr, buf, sizeof(buf));
        if(ret == 0) {
          printf("Bye");
          break;
        }
        printf(":%s\n",buf);
      }
      if(FD_ISSET(0, &redset)){ 
        memset(buf, 0, sizeof(buf));
        ret = read(0,buf,sizeof(buf));

        if(ret == 0) {
          printf("Bye");
          break;
        }
        ret =  write(fdw, buf, sizeof(buf)-1);
      }}  

  }
  close(fdr);
  close(fdw);
  return 0;
}

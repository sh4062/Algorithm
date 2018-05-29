#include "login.h"

int login(char*user, char*pwd) {
  char * cpwd =(char*) calloc(1,44);
  cpwd = crypt(pwd, "$5$elephant");
  FILE *p = fopen("db","w+");
  fprintf(p,"pwd:%s",cpwd);
  fclose(p);
  return 0;
}

int main(int argc,char**argv){
   login(argv[1],argv[2]);
}


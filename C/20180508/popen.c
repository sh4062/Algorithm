#include "fun.h"

int main(){
  FILE *read_fp;
  char buf[100+1];
  int chars_read;

  memset(buf, '\0', 101);
  read_fp = popen("ps -ax","r");
  if(read_fp != NULL){
    chars_read = fread(buf, sizeof(char), 100, read_fp);
    while(chars_read > 0) {
      buf[chars_read - 1] = '\0';
      printf("asdsadas\n  %s",buf);
      chars_read = fread(buf, sizeof(char),100,read_fp);
    }
    pclose(read_fp);
    exit(EXIT_SUCCESS);
  
  }
  
    exit(EXIT_SUCCESS);
}


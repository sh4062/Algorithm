

int main(){
  char *p;
  p = (char*)mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  if((char*)-1==p){
    perror("mmap");
    return -1;
  }
}

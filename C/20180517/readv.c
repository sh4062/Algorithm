#include "fun.h"

int main() {
  struct iovec iov[2];
  char buf1[10] = {0};
  char buf2[11] = {0};
  iov[0].iov_base = buf1;
  iov[0].iov_len = 9;
  iov[1].iov_base = buf2;
  iov[1].iov_len = 10;
  int fd = open("file1",O_RDWR);
  readv(fd,iov,2);
  printf("%s %s",buf1,buf2);
  close(fd);

} 

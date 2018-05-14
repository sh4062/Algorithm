#include "fun.h"

int main(){
  int server_sockfd;
  int client_sockfd;
  int len;
  struct sockaddr_in my_addr;
  struct sockaddr_in remote_addr;
  int sin_size;
  char buf[BUFSIZ];
  memset(&my_addr, 0, sizeof(my_addr));
}

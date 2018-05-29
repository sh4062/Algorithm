#include "fun.h"

int main(int argc, char*argv[]){
  if(argc != 3) {
    printf("Wrong Args");
    return -1;
  }
  int sfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sfd == -1){
    perror("socket");
    return -1;
  }
  struct sockaddr_in ser;
  struct sockaddr_in client;
  bzero(&ser, sizeof(ser));
  ser.sin_family = AF_INET;
  ser.sin_port = htons(atoi(argv[2]));
  ser.sin_addr.s_addr = inet_addr(argv[1]);
  int ret;
  char buf[128] = {0};
  bzero(&client,sizeof(client));
  int len;
  fd_set fdset;
  while(1){
    FD_ZERO(&fdset);
    FD_SET(0, &fdset);
    FD_SET(sfd, &fdset);
    ret = select(sfd + 1, &fdset, NULL, NULL, NULL);
    if(ret > 0) {
      if(FD_ISSET(sfd,&fdset)) {
        len = sizeof(struct sockaddr);
        memset(buf, 0, sizeof(buf));
        ret = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&ser,&len);
        printf("%s\n",buf);
        printf("server ip = %s, port = %d \n",inet_ntoa(ser.sin_addr), ntohs(ser.sin_port));
      }
      if(FD_ISSET(0,&fdset)) {
        memset(&buf, 0, sizeof(buf));
        read(0, buf, sizeof(buf));
        sendto(sfd, buf, strlen(buf)-1, 0, (struct sockaddr*)&ser, (sizeof(struct sockaddr)));
      }
    
    
    }
  
  
  }
  close(sfd);
  return 0;
}

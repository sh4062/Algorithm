#include "factory.h"

int main(int argc, char*argv[]){
  if(argc != 5) {
    printf("Args Error!"); 
    return -1;
  }
  int pnum = atoi(argv[3]);
  int cap = atoi(argv[4]);
  factory f;
  factory_init(&f, pnum, cap);
  factory_start(&f);
  int sfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sfd == -1) {
    perror("socket\n");
    return -1;
  }
  int reuse =1;
  int ret = setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int));
  if(ret == -1) {
    perror("socketopt\n");
    return -1;
  }
  struct sockaddr_in ser;
  bzero(&ser,sizeof(struct sockaddr_in));
  ser.sin_addr.s_addr = inet_addr (argv[1]);
  ser.sin_port = htons(atoi(argv[2]));
  ser.sin_family = AF_INET;
  ret = bind(sfd, (struct sockaddr*)&ser, sizeof(ser));
  if(ret == -1) {
    perror("bind");
    return -1;
  }
  listen(sfd, cap);
  int new_fd;
  pnode_t pnew;
  pque_t pq = &f.que;
  printf("waiting\n");
  struct sockaddr_in client;
	socklen_t len;
  while(1) {
    len=sizeof(struct sockaddr);
		new_fd=accept(sfd,(struct sockaddr*)&client,&len);
    printf("client ip=%s,port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
    pnew = (pnode_t)calloc(1, sizeof(node_t));
    pnew->new_fd = new_fd;
    pthread_mutex_lock(&pq->que_mutex);
    que_insert(pq, pnew);
    pthread_mutex_unlock(&pq->que_mutex);
    pthread_cond_signal(&f.cond);
  }


}



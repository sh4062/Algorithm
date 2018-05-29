#include "http.h"

#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"

void headers(int);
void cat(int,FILE*);

int main(int argc, char*argv[])
{
  if(argc != 3)
  {
    printf("Wrong Args!");
    return -1;
  }
  int  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sfd == -1)
  {
    perror("socket");
    return -1;
  }
  printf("sfd = %d\n", sfd);
  struct sockaddr_in ser;
  bzero(&ser, sizeof(ser));
  ser.sin_family = AF_INET;
  ser.sin_port = htons(atoi(argv[2]));
  ser.sin_addr.s_addr = inet_addr(argv[1]);
  int ret = bind(sfd, (struct sockaddr*)&ser, sizeof(struct sockaddr));
  listen(sfd, 10);
  int new_fd;
  struct sockaddr_in client;
  socklen_t len = sizeof(client);
  new_fd = accept(sfd, (struct sockaddr *)&client, &len);
  char buf[4096] = {0};
  ret = recv(new_fd, buf, sizeof(buf), 0);
  printf("%s\n", buf);
  bzero(buf, sizeof(buf));
  headers(new_fd);
  FILE *fp = fopen("index.html", "r+");
  cat(new_fd, fp);
  return 0;
}

void headers(int client) 
{
  char buf[1024];
  strcpy(buf, "HTTP/1.0 200 OK\r\n");
  send(client, buf, strlen(buf), 0);
  strcpy(buf, SERVER_STRING);
  send(client, buf, strlen(buf), 0);
  sprintf(buf, "Content-Type: text/html\r\n");
  send(client, buf, strlen(buf), 0);
  strcpy(buf, "\r\n");
  send(client, buf, strlen(buf), 0);
}

void cat(int client, FILE * res)
{
  char buf[1024];
  fgets(buf, sizeof(buf),res);
  while(!feof(res))
  {
    send(client, buf, strlen(buf), 0);
    fgets(buf, sizeof(buf), res);
  }
}

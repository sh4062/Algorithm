#include "fun.h"
typedef struct tagmag
{
  int client_pid ;
  char my_data[512] ;
}MSG;
int main(){
  int server_fifo_fd , client_fifo_fd ;
  char client_fifo[256];
  MSG my_msg ;
  char * pstr ;
  memset(&my_msg , 0 , sizeof(MSG));
  mkfifo("pipe1",0777);
  server_fifo_fd = open("./pipe1",O_RDONLY);
  if(server_fifo_fd == -1)
  {
    perror("server_fifo_fd");
    exit(-1);
  } 
  int iret ;
  while((iret = read(server_fifo_fd , &my_msg ,sizeof(MSG))>0))
  { 
    // iret = read(server_fifo_fd , &my_msg ,sizeof(MSG));
    pstr = my_msg.my_data ;
    printf("%s\n",my_msg.my_data);
    while(*pstr != '\0')
    {
      *pstr = toupper(*pstr);
      pstr ++ ;
    } 
    memset(client_fifo , 0 , 256);
    sprintf(client_fifo , "CLIENT_FIFO_%d" , my_msg.client_pid);
    client_fifo_fd = open(client_fifo , O_WRONLY);
//    memset(&my_msg,0,sizeof(MSG));
    strcpy(my_msg.my_data,client_fifo);
    if(client_fifo_fd == -1)
    { 
      perror("client_fifo_fd");
      exit(-1);
    }
    write(client_fifo_fd , &my_msg, sizeof(MSG));
    printf("send:%s\n", my_msg.my_data);
    printf("OVER!\n");
    close(client_fifo_fd);
  } 
  return 0 ;
}

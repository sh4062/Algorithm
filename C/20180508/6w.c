#include "fun.h"
/*id就是指每个消息队列的标记值，而key值就是表示如何找到这个消息队列，对于一个准备发送消息的进程，通过ftok（）函数，可以将指定的文件加上自定义的值一般是项目ID作为key值，创建一个消息队列，而在另一个准备接受的进程里，它不知道要在哪个消息队列里接收消息，于是它也通过一个指定的文件加上自定义的值例如项目ID作为key值，然后通过key值找到所属的消息队列。所以这个key值属于要通信的进程双方互相沟通好的，作为在内核里找到它们专属的消息队列的桥梁。
*/
int main(){
  key_t key = ftok("./key.key",1);//1 is id
  if(key == -1){
    perror("ftok");
    exit(-1);
  }
  int shmid = shmget(key, 4096, IPC_CREAT);
  if(shmid == -1){
    perror("shmget");
    exit(-1);
  }

  char *pm =(char*)shmat (shmid, NULL,0);
  if ( (int)pm == -1 )
  {
    perror("shmat addr error") ;
    return -1 ;
  }
  memset(pm,0, 4096);
  char buf[4096] = {0};
  strcpy(buf,"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  //memcpy(pm, "?????? sadasd sdaaaaaaaaaaaaaaaazxcxzfdasxckjvhcnxzkjlfherjikafhxasdasdczxc,mvnxkzjdh",1829);
  memcpy(pm,buf,4096);
  if(shmdt(pm) == -1){
    perror("shmdt");
    exit(-1);
  }


}

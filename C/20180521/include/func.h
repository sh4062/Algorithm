#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <signal.h>
#include <pthread.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <sys/uio.h>
typedef struct{
	pid_t pid;
	int fd;//管道，用来传递控制信息
	short busy;//用来标识子进程是否忙碌
}Data,*pData;
#define FILENAME "file"
void make_child(pData,int);
void child_handle(int);
void recv_fd(int,int*);
void send_fd(int,int);
void trans_file(int);
int send_n(int,char*,int);
typedef struct{
	int len;
	char buf[1000];
}train;
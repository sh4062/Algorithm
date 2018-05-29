#ifndef __FUNC_H__
#define __FUNC_H__
#include "md5.h"
#include<unistd.h>
#include <ctype.h>
#include<stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<dirent.h>
#include<string.h>
#include <limits.h>
#include <sys/select.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <sys/sem.h>
#include <pthread.h>
#include <sys/msg.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <sys/uio.h>
#include <crypt.h>
//#include<openssl/md5.h>
// int send_n(int sfd,char* p,int len);
// int recv_n(int sfd,char* p,int len);
// void trans_file(int sfd, char *FILENAME);
typedef struct {
  int len;
  char buf[8192];
}train;
#endif
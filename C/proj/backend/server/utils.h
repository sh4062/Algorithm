#include "fun.h"
#include "factory.h"
int fd_Setnonblocking(int fd) ;
int send_n(int sfd,char* p,int len);
int recv_n(int sfd,char* p,int len);
void trans_file(int sfd, char *filename, char *path,off_t filesize_truncated);

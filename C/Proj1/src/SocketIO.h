#ifndef _OH_NET_SOCKETSOPS_H_
#define _OH_NET_SOCKETSOPS_H_

#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/eventfd.h>
#include <sys/epoll.h>
namespace oh
{
class SocketIO
{
    public: 
    SocketIO(int sockfd);
    size_t readline(char * buf, size_t max);
    size_t readn(char * buf, size_t count);
    size_t writen(const char * buf, size_t count);
    size_t recvPeek(char * buf, size_t count);
    private: 
    int  _sockfd;
};
} // namespace oh
#endif
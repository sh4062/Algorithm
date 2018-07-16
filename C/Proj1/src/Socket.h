#ifndef _OH_NET_SOCKETS_H_
#define _OH_NET_SOCKETS_H_
#include "Noncopyable.h"
#include "InetAddress.h"
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
inline int createSocketFd()
{
    int fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("socket create error!");
    }
    return fd;
}
namespace oh
{
class InetAddress;
class Socket : Noncopyable
{
  public:
    Socket(int sockfd);
    Socket();
    ~Socket();

    void shutdownWrite();
    int fd() const { return _sockfd; }

    void nonblock();

    static InetAddress getLocalAddr(int sockfd);
    static InetAddress getPeerAddr(int sockfd);

  private:
    int _sockfd;
};
} // namespace oh
#endif
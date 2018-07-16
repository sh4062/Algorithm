#include "Socket.h"
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <strings.h> // bzero
#include <stdio.h>   // snprintf
#include <fcntl.h>   //fcntl
using namespace oh;

void Socket::nonblock()
{
    int flags = ::fcntl(sockfd_, F_GETFL, 0);
    flags |= O_NONBLOCK;
    ::fcntl(sockfd_, F_SETFL, flags);
}

Socket::~Socket()
{
    ::close(sockfd_);
}

void Socket::setReuseAddr(bool on)
{
    int optval = on ? 1 : 0;
    int ret = ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEADDR,
                           &optval, static_cast<socklen_t>(sizeof optval));
}

void Socket::setReusePort(bool on)
{
    int optval = on ? 1 : 0;
    int ret = ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT,
                           &optval, static_cast<socklen_t>(sizeof optval));
}
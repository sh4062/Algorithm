#include "Socket.h"
using namespace oh;


inline void setNonblock(int fd)
{
    int flags = ::fcntl(fd, F_GETFL, 0);
    flags |= O_NONBLOCK;
    ::fcntl(fd, F_SETFL, flags);
}
Socket::Socket(int sockfd)
    : _sockfd(sockfd)
{
}

Socket::Socket()
    : _sockfd(createSocketFd())
{
}

Socket::~Socket()
{
    ::close(_sockfd);
}

void Socket::nonblock()
{
    setNonblock(_sockfd);
}

void Socket::shutdownWrite()
{
    if (::shutdown(_sockfd, SHUT_WR) == -1)
    {
        perror("shudown write error!");
    }
}

InetAddress Socket::getLocalAddr(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getsockname(sockfd, (struct sockaddr *)&addr, &len) == -1)
	{
		perror("getsockname error");
	}
	return InetAddress(addr);
}

InetAddress Socket::getPeerAddr(int sockfd)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(sockaddr_in);
	if(::getpeername(sockfd, (struct sockaddr *)&addr, &len) == -1)
	{
		perror("getpeername error");
	}
	return InetAddress(addr);
}
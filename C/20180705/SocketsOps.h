#ifndef _M_NET_SOCKETSOPS_H
#define _M_NET_SOCKETSOPS_H

#include <arpa/inet.h>

namespace m
{
namespace net
{
namespace sockets
{

int connect(int sockfd, const struct sockaddr* addr);
void close(int sockfd);
}
} // namespace net
} // namespace m

#endif
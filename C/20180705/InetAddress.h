#ifndef _M_INETADDRESS_H
#define _M_INETADDRESS_H

#include <netinet/in.h>
#include <string>

namespace m
{
namespace net
{
namespace sockets
{
const struct sockaddr *sockaddr_cast(const struct sockaddr_in6 *addr);
} // namespace sockets

class InetAddress
{
  public:
    explicit InetAddress(uint16_t port = 0, bool loopbackOnly = false, bool ipv6 = false);

    InetAddress(const char *pIp, short port);

    explicit InetAddress(const struct sockaddr_in &addr);

    const struct sockaddr_in *getSockAddrPtr() const;
    std::string ip() const;
    sa_family_t family() const { return addr_.sin_family; }
    std::string toIp() const;
    std::string toIpPort() const;
    uint16_t toPort() const;
    uint32_t ipNetEndian() const;
    uint16_t portNetEndian() const { return addr_.sin_port; }

  private:
    struct sockaddr_in addr_;
};
} // namespace net
} // end of namespace m

#endif
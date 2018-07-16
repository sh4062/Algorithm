#ifndef _OH_INET_ADDRESS_H_
#define _OH_INET_ADDRESS_H_
#include <netinet/in.h>
#include <string>
using namespace std;
namespace oh
{
class InetAddress
{
  public:
    InetAddress(unsigned short);
    InetAddress(const char *ip, unsigned short);
    InetAddress(const struct sockaddr_in &addr);
    string ip() const;
    unsigned short port() const;

  private:
    struct sockaddr_in _addr;
};
} // namespace oh
#endif
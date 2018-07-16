#include "InetAddress.h"
#include "string.h"
#include <arpa/inet.h>
using namespace oh;
//构造函数
InetAddress::InetAddress(unsigned short port)
{
    bzero(&_addr, sizeof _addr);
    _addr.sin_family = AF_INET;
    _addr.sin_addr.s_addr = INADDR_ANY;
    _addr.sin_port = htons(port);
}
//构造函数
InetAddress::InetAddress(const char *ip, unsigned short port)
{
    bzero(&_addr, sizeof _addr);
    _addr.sin_family = AF_INET;
    _addr.sin_addr.s_addr = inet_addr(ip);
    _addr.sin_port = htons(port);
}
//构造函数
InetAddress::InetAddress(const struct sockaddr_in &addr)
    : _addr(addr)
{
}
//get ip
string InetAddress::ip() const
{
    return std::string(inet_ntoa(_addr.sin_addr));
}

unsigned short InetAddress::port() const{
    return  ntohs(_addr.sin_port);
}
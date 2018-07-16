#include "InetAddress.h"

using namespace m;
using namespace m::net;


string InetAddress::toIpPort() const
{
  char buf[64] = "";
  sockets::toIpPort(buf, sizeof buf, getSockAddr());
  return buf;
}

string InetAddress::toIp() const
{
  char buf[64] = "";
  sockets::toIp(buf, sizeof buf, getSockAddr());
  return buf;
}

uint32_t InetAddress::ipNetEndian() const
{
  assert(family() == AF_INET);
  return addr_.sin_addr.s_addr;
}

uint16_t InetAddress::toPort() const
{
  return sockets::networkToHost16(portNetEndian());
}
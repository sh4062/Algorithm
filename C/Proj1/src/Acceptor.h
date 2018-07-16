#ifndef _OH_ACCEPTOR_H_
#define _OH_ACCEPTOR_H_
#include "InetAddress.h"
#include "Socket.h"
namespace oh
{
class Acceptor
{
  public:
    Acceptor(int listenfd, const InetAddress &addr);

    void ready();
    int accept();

    int fd() const { return _listenSock.fd(); }

  private:
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void bind();
    void listen();

  private:
    Socket _listenSock;
    InetAddress _addr;
};
} // namespace oh

#endif
#ifndef _M_SOCKET_H_
#define _M_SOCKET_H_
#include <boost/noncopyable.hpp>
// struct tcp_info is in <netinet/tcp.h>
struct tcp_info;
namespace m
{
namespace net
{
class InetAddress;
class Socket
    : boost::noncopyable
{
  public:
    //取消了隐式转换
    explicit Socket(int sockfd)
        : _sockfd(sockfd)
    {
    }
    ~Socket();
    int fd() const { return _sockfd; } 
    bool getTcpInfo(struct tcp_info*) const;
    bool getTcpInfoString(char* buf, int len) const;
    //abort if address in use->2
    void bindAddress(const InetAddress & localaddr);
    void listen();

    int accept(InetAddress* peeraddr);

    void shutdownWrite();

    void setTcpNoDelay(bool on);
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void setKeepAlive(bool on);
  private:
    const int _sockfd;
};

} // namespace net

} // namespace m
#endif
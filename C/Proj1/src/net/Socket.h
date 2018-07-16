/*
 * File: Socket.h
 * Project: net
 * File Created: Tuesday, 10th July 2018 8:58:47 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 10th July 2018 9:00:25 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_NET_SOCKET_H_
#define _OH_NET_SOCKET_H_
#include <boost/noncopyable.hpp>

struct tcp_info;

namespace oh
{
class InetAddress;
class Socket : boost::noncopyable
{
  public:
    explicit Socket(int sockfd)
        : sockfd_(sockfd) {}
    ~Socket();
    int fd() const { return sockfd_; }
    void shutdownWrite();
    void nonblock();
    ///
    /// Enable/disable SO_REUSEADDR
    ///
    void setReuseAddr(bool on = true);

    ///
    /// Enable/disable SO_REUSEPORT
    ///
    void setReusePort(bool on = true);

  private:
    const int sockfd_;
};
} // namespace oh
#endif
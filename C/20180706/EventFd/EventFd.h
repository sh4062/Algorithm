#ifndef _M_EVENTFD_H_
#define _M_EVENTFD_H_
#include <functional>
//用于线程间的通信  计算线程通知io
namespace m
{
class Eventfd
{
  public:
    using Callback = std::function<void()>;
    Eventfd(Callback &&cb);
    void start();
    void stop();
    void wakeup();

  private:
    void handleRead();

  private:
    int _fd;
    Callback _cb;
    bool _isStarted;
};

} // namespace m
#endif
#ifndef _OH_TIMER_H
#define _OH_TIMER_H
#include <functional>
namespace oh
{
class Timer
{
public:
  using Callback = std::function<void()>;
  Timer(int initialTime, int intervalTime, Callback &&cb);

  ~Timer();

  void start();
  void stop();

private:
  int createTimerFd();
  void setTimerfd(int initialTime, int intervalTime);
  void handleRead();

private:
  int _fd;
  int _inittime;
  int _intervaltime;
  Callback _cb;
  bool _isStarted;
};

} // namespace oh
#endif
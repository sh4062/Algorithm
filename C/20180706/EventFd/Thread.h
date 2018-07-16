#ifndef __M_THREAD_H__
#define __M_THREAD_H__

#include "Noncopyable.h"

#include <pthread.h>
#include <functional>
using std::function;

namespace m
{

class Thread
    : Noncopyable // 表达语义
{
    using ThreadCallback = function<void()>;

  public:
    Thread(ThreadCallback &&cb);
    ~Thread();

    void start();
    void join();

    bool isRunning() const { return _isRunning; }

  private:
    static void *threadFunc(void *); //采用静态成员函数，就是为了去掉this的影响
  private:
    pthread_t _pthid;
    bool _isRunning;
    ThreadCallback _cb;
};
} //end of namespace m

#endif
/*
 * File: thread.h
 * Project: thread
 * File Created: Wednesday, 4th July 2018 2:14:33 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 2:14:43 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_THREAD_H
#define _OH_THREAD_H
#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace oh
{
class Thread
    : Noncopyable
{
    using ThreadCallback = std::function<void()>;

  public:
    Thread(ThreadCallback &&cb);
    ~Thread();
    void start();
    void join();
    bool isRunning()
    {
        return _isRunning;
    }

  private:
    static void *threadFunc(void *);

  private:
    pthread_t _pthid;
    bool _isRunning;
    ThreadCallback _cb;
};
} // namespace oh

#endif
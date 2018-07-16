/*
 * File: Condition.h
 * Project: pool
 * File Created: Wednesday, 4th July 2018 8:11:04 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 8:11:07 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "Noncopyable.h"
#include "mutex.h"
#include <pthread.h>

namespace oh
{
class Condition
    : public Noncopyable
{
  public:
    Condition(MutexLock &mutex)
        : _mutex(mutex)
    {
        pthread_cond_init(&_cond, NULL);
    }

    ~Condition()
    {
        pthread_cond_destroy(&_cond);
    }

    void wait()
    {
        pthread_cond_wait(&_cond, _mutex.getMutexLockPtr());
    }

    void notify()
    {
        pthread_cond_signal(&_cond);
    }

    void notifyAll()
    {
        pthread_cond_broadcast(&_cond);
    }

  private:
    pthread_cond_t _cond;
    MutexLock &_mutex;
};
} // namespace oh
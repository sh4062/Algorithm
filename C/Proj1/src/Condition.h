/*
 * File: Condition.h
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 11:41:11 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 11:41:18 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_CONDITION_H_
#define _OH_CONDITION_H_
#include "Noncopyable.h"
#include "mutex.h"
#include <pthread.h>
namespace oh
{
class Condition
    : Noncopyable
{
  public:
    Condition(MutexLock &mutex)
        : _mutex(mutex)
    {
        pthread_cond_init(&_cond, NULL);
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

#endif
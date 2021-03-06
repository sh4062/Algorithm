/*
 * File: mutex.h
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 12:23:48 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 8:28:01 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _oh_mutexlock_h
#define _oh_mutexlock_h

#include "Nocopyable.h"
#include <pthread.h>
namespace oh
{
class MutexLock
{
  public:
    MutexLock()
    {
        pthread_mutex_init(&_mutex, NULL);
    }
    ~MutexLock()
    {
        pthread_mutex_destroy(&_mutex);
    }

    void lock()
    {
        pthread_mutex_lock(&_mutex);
    }

    void unlock()
    {
        pthread_mutex_unlock(&_mutex);
    }

    pthread_mutex_t *getMutexLockPtr()
    {
        return &_mutex;
    }

  private:
    pthread_mutex_t _mutex;
};
//RAII
class MutexLockGuard
{
  public:
    MutexLockGuard(MutexLock &mutex)
        : _mutex(mutex)
    {
        _mutex.lock();
    }

    ~MutexLockGuard()
    {
        _mutex.unlock();
    }

  private:
    MutexLock &_mutex;
};
} // namespace oh

#endif
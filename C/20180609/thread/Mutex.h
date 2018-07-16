/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：Mutex.h
*   Creator    ：Max
*   Date       ：2018/06/11
*   Description：
*
================================================================*/
#include "pthread.h"
namespace thread_n
{
class MutexLock

{

public:
  //...
  MutexLock();
  ~MutexLock();
  void lock();
  void unlock();
  pthread_mutex_t *getMutexLockPtr() { return &_mutex; }
  //一般是值语义
  //禁止复制 --> 对象语义
  MutexLock(const MutexLock &) = delete; //C++11
private:                                 //C++98
  MutexLock &operator=(const MutexLock &);

private:
  //...
  pthread_mutex_t _mutex;
  bool _islock;
};

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
} // namespace thread_n

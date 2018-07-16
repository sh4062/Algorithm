 ///
 /// @file    MutexLock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 16:19:50
 ///
 

#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include <pthread.h>

namespace wd
{

//能够进行复制  --> 值语义

class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexLockPtr(){	return &_mutex;	}
//禁止复制 --> 对象语义
	MutexLock(const MutexLock &) =delete;//C++11
private://C++98
	MutexLock & operator=(const MutexLock &);
	
private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	: _mutex(mutex)
	{	_mutex.lock();	}

	~MutexLockGuard()
	{	_mutex.unlock();	}

private:
	MutexLock & _mutex;
};

}// end of namespace wd

#endif

/*
 * File: thread.h
 * Project: 面向对象
 * File Created: Tuesday, 3rd July 2018 9:40:17 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 9:40:20 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_THREAD_H
#define _OH_THREAD_H
#include "Noncopyable.h"
#include <functional>
#include <pthread.h>
using namespace std;

namespace oh
{
class Thread
: Noncopyable // 表达语义
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();
	
	bool isRunning() const {	return _isRunning;	}
    static __thread int _tNUmber;

private:
	virtual void run() =0;// 就是线程要执行的任务

	static void * threadFunc(void *);

private:
	pthread_t _pthid;
	bool _isRunning;
};
} // namespace oh

#endif
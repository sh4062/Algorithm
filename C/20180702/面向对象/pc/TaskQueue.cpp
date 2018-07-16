/*
 * File: TaskQueue.cpp
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 9:26:50 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 9:26:51 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "TaskQueue.h"

using namespace oh;
 
//生产者所在的线程
void TaskQueue::push(const Task & t)
{
	MutexLockGuard autoLock(_mutex);

	while(full())	
	{
		_notFull.wait();
	}

	_que.push(t);
	_notEmpty.notify();
}

//消费者所在的线程
Task TaskQueue::pop()
{
	MutexLockGuard autoLock(_mutex);
	while(empty())
	{
		_notEmpty.wait();
	}

	Task t = _que.front();
	_que.pop();
	_notFull.notify();

	return t;
}
/*
 * File: TaskQueue.cpp
 * Project: pool
 * File Created: Wednesday, 4th July 2018 10:11:20 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 10:11:21 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "TaskQueue.h"

using namespace oh;
 
//生产者所在的线程
void TaskQueue::push(Task * t)
{
	MutexLockGuard autoLock(_mutex);

	while(full())	
	{
		_notFull.wait();
	}

	_queue.push(t);
	_notEmpty.notify();
}

//消费者所在的线程
Task *TaskQueue::pop()
{
	MutexLockGuard autoLock(_mutex);
	while(empty())
	{
		_notEmpty.wait();
	}

	Task *t = _queue.front();
	_queue.pop();
	_notFull.notify();

	return t;
}
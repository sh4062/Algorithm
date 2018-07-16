/*
 * File: TaskQueue.h
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 8:38:49 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 8:40:45 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef __OH_TASKQUEUE_H__
#define __OH_TASKQUEUE_H__

#include "mutex.h"
#include "Condition.h"

#include <queue>


namespace oh
{

typedef int Task;

class TaskQueue
{
public:
	TaskQueue(size_t queSize)
	: _queSize(queSize)
	, _mutex()
	, _notFull(_mutex)
	, _notEmpty(_mutex)
	{}
	
	void push(const Task & t);
	Task pop();

	bool empty() const
	{	return _que.size() == 0;	}

	bool full()const
	{	return _que.size() == _queSize;	}

private:
	size_t _queSize;
	std::queue<Task> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};


}//end of namespace wd

#endif
/*
 * File: Threadpool.h
 * Project: pool
 * File Created: Wednesday, 4th July 2018 10:03:08 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 10:03:09 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_THREAD_POOL_H_
#define _OH_THREAD_POOL_H_
#include <vector>
#include <memory>
#include "TaskQueue.h"
using namespace std;
namespace oh
{
class Task
{
  public:
    virtual void process() = 0;
};
class Thread;
class WorkerThread;
class Threadpool
{
	friend WorkerThread;
public:
	Threadpool(size_t threadNum, size_t queSize)
	: _threadNum(threadNum)
	, _queSize(queSize)
	, _taskQue(_queSize)
	, _isExit(false)
	{
		_threads.reserve(_threadNum);
	}

	~Threadpool();

	void start();
	void stop();
	void addTask(Task *);

private:
	void threadFunc();
	Task * getTask();

private:
	size_t _threadNum;
	size_t _queSize;
	vector<shared_ptr<Thread> > _threads;
	TaskQueue _taskQue;
	bool _isExit;
};
} // namespace oh
#endif
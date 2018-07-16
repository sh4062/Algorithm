/*
 * File: Threadpool.cpp
 * Project: pool
 * File Created: Wednesday, 4th July 2018 10:14:41 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 10:14:42 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "Threadpool.h"
#include "Thread.h"
#include "WorkerThread.h"
#include <unistd.h>
#include <iostream>
using namespace std;
using namespace oh;
struct TreadData
{
	Thread &t;
	size_t idx;
};

void Threadpool::start()
{
	for (size_t idx = 0; idx < _threadNum; ++idx)
	{
		shared_ptr<Thread> pThread(new WorkerThread(*this));
		pThread->_tNUmber = idx;
		_threads.push_back(std::move(pThread));
	}

	for (auto &pThread : _threads)
	{
		pThread->start();
	}
}

//运行在主线程中
void Threadpool::stop()
{
	if (!_isExit)
	{
		while (!_taskQue.empty())
		{
			::sleep(1);
			cout << ">>> Threadpool sleep 1 s" << endl;
		}

		_isExit = true;
		cout << ">>> Threadpool -> stop: _isExit = " << _isExit << endl;

		_taskQue.wakeup();

		for (auto &pthread : _threads)
		{
			pthread->join();
		}
	}
}

Threadpool::~Threadpool()
{
	if (!_isExit)
	{
		stop();
	}
}

void Threadpool::addTask(Task *ptask)
{
	_taskQue.push(ptask);
}

Task *Threadpool::getTask()
{
	return _taskQue.pop();
}

//子线程要做的事情
void Threadpool::threadFunc()
{
	while (!_isExit)
	{
		Task *ptask = getTask();
		if (ptask)
		{
			cout << "ptask->process()\n";
			ptask->process(); //执行任务的时间不确定
		}
	}
}
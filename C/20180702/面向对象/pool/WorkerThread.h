/*
 * File: WorkerThread.h
 * Project: pool
 * File Created: Wednesday, 4th July 2018 10:17:40 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 10:17:41 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef __OH_WORKERTHREAD_H__
#define __OH_WORKERTHREAD_H__

#include "Thread.h"
#include <iostream>
using namespace std;

namespace oh
{

class Threadpool;

class WorkerThread
: public Thread
{
public:
	WorkerThread(Threadpool & threadpool)
	: _threadpool(threadpool)
	{	cout << "WorkerThread()" << endl;	}


	~WorkerThread() {	cout << "~WorkThread()" << endl;	}
private:
	void run();
	Threadpool & _threadpool;
};

}//end of namespace wd

#endif
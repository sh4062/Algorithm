

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
	WorkerThread(Threadpool &threadpool)
		: _threadpool(threadpool)
	{
		cout << "WorkerThread()" << endl;
	}

	~WorkerThread() { cout << "~WorkThread()" << endl; }

  private:
	void run();
	Threadpool &_threadpool;
};
} // namespace oh

#endif

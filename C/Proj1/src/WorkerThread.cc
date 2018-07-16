#include "WorkerThread.h"
#include "Threadpool.h"


using namespace oh;

void WorkerThread::run()
{
	
	cout<<"WorkerThread::run()\n";
	_threadpool.threadFunc();
}
	
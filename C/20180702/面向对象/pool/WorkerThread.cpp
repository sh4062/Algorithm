#include "WorkerThread.h"
#include "Threadpool.h"


using namespace oh;

void WorkerThread::run()
{
	_threadpool.threadFunc();
}
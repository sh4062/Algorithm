#ifndef _M_TIMERTHREAD_H
#define _M_TIMERTHREAD_H
#include "timer.h"
#include "Thread.h"

#include <functional>

namespace m
{
	
class TimerThread
{
public:
	using TimerCallback = std::function<void()>;
	TimerThread(int, int, TimerCallback && cb);

	void start();
	void stop();

	~TimerThread();

private:
	Timer _timer;
	Thread _subThread;
	bool _isStarted;
};
}//end of namespace m

#endif
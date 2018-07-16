/*
 * File: producer.h
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 8:47:50 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 8:47:56 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "thread.h"
#include "TaskQueue.h"

namespace oh
{

class Producer
: public Thread
{			
public:
	Producer(TaskQueue & tq)
	: _tq(tq)
	{}

private:			
	void run();

	TaskQueue & _tq;
};

}
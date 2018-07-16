/*
 * File: test.cpp
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 8:47:33 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 8:47:34 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "consumer.h"
#include "producer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace oh;

 
int main(void)
{
	cout << "MainThread: " << pthread_self() << endl;

	TaskQueue tq(10);

	unique_ptr<oh::Thread> pProducer(new Producer(tq));
	unique_ptr<oh::Thread> pConsumer(new Consumer(tq));
	pProducer->start();
	pConsumer->start();

	pProducer->join();
	pConsumer->join();

	return 0;
}
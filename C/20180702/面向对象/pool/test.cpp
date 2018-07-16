/*
 * File: test.cpp
 * Project: pool
 * File Created: Wednesday, 4th July 2018 10:27:59 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 10:28:00 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */

#include "Threadpool.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace oh;


class MyTask
: public Task
{
public:
	void process()
	{
		::srand(::time(NULL));
		//::srand(::clock());
		int number = ::rand() % 100;
		cout << ">>> subThread: "<< pthread_self() << ". produce a number : " << number << endl;
		::sleep(1);
	}
};

 
int main(void)
{
	cout << "MainThread: " << pthread_self() << endl;

	unique_ptr<Task> ptask(new MyTask());

	Threadpool threadpool(4, 10);
	threadpool.start();

	int cnt = 30;
	while(cnt--) {
		threadpool.addTask(ptask.get());
		cout << "MainThread: "<< cnt << endl;
	}
	threadpool.stop();

	return 0;
}
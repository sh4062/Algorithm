/*
 * File: test.cpp
 * Project: thread
 * File Created: Wednesday, 4th July 2018 2:15:35 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 2:15:36 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "thread.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

struct MyTask{
	void run(){
		::srand(::time(NULL));
		int cnt = 10;
		while(cnt--) {
			int number = ::rand() % 100;
			cout << ">> Thread "<< pthread_self() << " get a number : " << number << endl;
			::sleep(1);
		}
	}
};
 
int main(void)
{
	cout << "MainThread: " << pthread_self() << endl;
	oh::Thread myThread(std::bind(&MyTask::run, MyTask()));
	myThread.start();
	myThread.join();

	return 0;
}
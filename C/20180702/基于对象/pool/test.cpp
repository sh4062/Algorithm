/*
 * File: test.cpp
 * Project: pool
 * File Created: Wednesday, 4th July 2018 8:24:57 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 8:24:58 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "thread.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>


using namespace oh;
using std::cout;
using std::endl;

struct Producer{
	void produceNumber(TaskQueue & tq){
		::srand(::time(NULL));
		int cnt = 5;
		while(cnt--) {
			int number = ::rand() % 100;
			tq.push(number);
			cout << ">> Thread "<< pthread_self() << " get a number : " << number << endl;
			::sleep(1);
		}
	}
};

struct Consumer{
	void consumeNumber(TaskQueue & tq) {
		int cnt = 5;
		while(cnt--) {
			int number = tq.pop();
			cout << ">> Thread "<< pthread_self() << " consumer a number : " << number << endl;
			::sleep(2);
		}
	}
};

void produce(TaskQueue & tq){
	::srand(::time(NULL));
	int cnt = 5;
	while(cnt--) {
		int number = ::rand() % 100;
		tq.push(number);
		cout << ">> Thread "<< pthread_self() << " get a number : " << number << endl;
		::sleep(1);
	}
}

void consume(TaskQueue & tq) {
	int cnt = 5;
	while(cnt--) {
		int number = tq.pop();
		cout << ">> Thread "<< pthread_self() << " consumer a number : " << number << endl;
		::sleep(2);
	}
}
 
int main(void)
{
	cout << "MainThread: " << pthread_self() << endl;

	TaskQueue tq(10);
	//wd::Thread producer(std::bind(&Producer::produceNumber, Producer(), std::ref(tq)));
	//wd::Thread consumer(std::bind(&Consumer::consumeNumber, Consumer(), std::ref(tq)));
	oh::Thread producer(std::bind(produce, std::ref(tq)));
	oh::Thread consumer(std::bind(consume, std::ref(tq)));
	producer.start();
	consumer.start();

	producer.join();
	consumer.join();
	return 0;
}
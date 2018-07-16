#include "thread.h"

#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class MyThread
: public oh::Thread
{
	void run()
	{
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
	unique_ptr<oh::Thread> myThread(new MyThread());//线程对象在主线程
	myThread->start();
	myThread->join();

	return 0;
}
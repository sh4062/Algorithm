 ///
 /// @file    testThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 17:12:36
 ///
 
#include "MutexLock.h"
#include "Condition.h"

#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
using namespace wd;


//要求:两个线程交替改变counter的值 


//系统资源在设计时应该设计成不能复制
MutexLock gMutex;
MutexLock mutex = gMutex;//error
Condition gCondition(gMutex);

int gCounter = 0;
int gFlag = false;

//当gFlag的值为false时， gCounter的值+1
void * threadFunc1(void * arg)
{
	int cnt = 10;
	while(cnt--){
		MutexLockGuard autoLock(gMutex);//自动加锁； 对象被销毁时自动解锁
		//gMutex.lock();
		if(gFlag){
			gCondition.wait();
		}
		++gCounter;
		cout << pthread_self() << ": gCounter = " << gCounter << endl;
		if(!gFlag)
		{
			gFlag = true;
			gCondition.notify();
		}
		//gMutex.unlock();
		return NULL;
		sleep(1);
	}
	return NULL;
}


//当gFlag的值为true时， gCounter的值+1
void * threadFunc2(void * arg)
{
	int cnt = 10;
	while(cnt--){
		MutexLockGuard autoLock(gMutex);
		if(!gFlag){
			gCondition.wait();
		}

		++gCounter;
		cout << pthread_self() << ": gCounter = " << gCounter << endl;
		if(gFlag){
			gFlag = false;
			gCondition.notify();
		}
		sleep(1);
	}

	return NULL;
}

 
int main(void)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, threadFunc1, NULL);
	pthread_create(&thread2, NULL, threadFunc2, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);


	return 0;
}

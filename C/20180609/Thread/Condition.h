 ///
 /// @file    Condition.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 16:29:33
 ///
 

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__
#include <pthread.h>

namespace wd
{

class MutexLock;//类的前向声明, 作用减少头文件的依赖,防止头文件的循环引用

class Condition
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyAll();

	Condition(const Condition &) = delete;
	Condition & operator=(const Condition &) = delete;

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;//占据一个指针大小
};

}//end of namespace wd


#endif

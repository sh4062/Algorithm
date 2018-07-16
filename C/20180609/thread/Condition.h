#include <pthread.h>

namespace thread_n
{

class MutexLock;//类的前向声明, 作用减少头文件的依赖,防止头文件的循环引用
//但是，仅仅进行前向声明而没有定义的类是不完整的，这样的类，只能用于定义指针、引用、以及用于函数形参的指针和引用。
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
#include "stdio.h"
#include "pthread.h"
#include <iostream>
using namespace std;
//单例对象的自动释放
//atexit + pthread_once
class Singleton 
{
    
    public: 
        static Singleton * getIns() {;
            pthread_once(&_po, init);
            return _sig;
        }
        static void init() {
            _sig = new Singleton;
            atexit(destroy);//作用是注册函数 当进程结束时调用 注册几次 执行几次 

        }

        static void destroy() {
            if(_sig) {
                delete _sig;
            }
            
        }
    private: 
        Singleton(){cout<<"Sin\n";}
        ~Singleton(){cout<<"~Sin\n";}
    private: 
        static Singleton * _sig;
        static pthread_once_t _po;

};
//Singleton* Singleton::_sig = NULL; //饿汉
Singleton* Singleton::_sig = getIns();//饱汉
pthread_once_t Singleton::_po = PTHREAD_ONCE_INIT;

int main() {
    Singleton * a = Singleton::getIns();
    return 0;
}
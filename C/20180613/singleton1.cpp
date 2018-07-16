#include "stdio.h"
#include <iostream>
using namespace std;
//单例对象的自动释放
//静态对象+嵌套类
class Singleton 
{
    class Auto {
        public:
        Auto(){cout<<"Auto\n";}
        ~Auto(){
            if(_sig) {
                delete _sig;
            }
            cout<<"~Auto\n";}

    };
    public: 
        //多线程下需要锁
        static Singleton * getIns() {;
            if(_sig == NULL) {
                _sig = new Singleton();
            } 
            
            return _sig;
        }
    private: 
        Singleton(){cout<<"Sin\n";}
        ~Singleton(){cout<<"~Sin\n";}
    private: 
        static Singleton * _sig;
        static Auto  _auto;

};
//Singleton* Singleton::_sig = NULL; //饿汉
Singleton* Singleton::_sig = getIns();//饱汉
Singleton::Auto  Singleton::_auto;

int main() {
    Singleton * a = Singleton::getIns();
    return 0;

}
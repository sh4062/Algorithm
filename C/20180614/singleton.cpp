/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：singleton.cpp
*   Creator    ：Max
*   Date       ：2018/06/17
*   Description：
*
================================================================*/

//单例模式是只能有一个实例化的对象的类
//构造函数声明为private或者protect防止被外部函数实例化，内部保存一个private
//static的指针保存唯一的实例，实例的动作由一个public的类方法代
//该方法返回单例模式唯一的实例
#include <stdio.h>
#include <iostream>
using namespace std;
template<typename T>
class singleton
{
  public:
    static T *instance();

  private:
    singleton(const singleton&) {}
    singleton& operator=(const singleton&){};

  private:
    static T *p;
};
template<typename T>
T *singleton<T>::p = NULL;
template<typename T>
T *singleton<T>::instance()
{
    if (p == NULL)
        p = new T();
    return p;
}
int main()
{
    int  *p1 = singleton<int>::instance();
    int  *p2= singleton<int>::instance();
    cout << p1 << endl
         << p2 << endl;
}

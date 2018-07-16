/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：singleton.cpp
*   Creator    ：Max
*   Date       ：2018/06/10
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
class singleton
{
protected:
  singleton(){}
private:
  static singleton *p;
public:
  static singleton *instance();
};

singleton * singleton::p = NULL;
singleton * singleton::instance()
{
  if(p == NULL) 
    p = new singleton();
  return p;

}

int main(){
  singleton *p1 = singleton::instance();
  singleton *p2 = singleton::instance();
  cout<<p1<<endl<<p2<<endl;
}

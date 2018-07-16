#include <iostream>
using namespace std;
class Base
{
  public:
    Base()
    {
        cout << "Base" << endl;
    }
    Base(int ib)
        : _ib(ib)
    {
        cout << "Base(int)" << endl;
    }
    ~Base()
    {
        cout << "~Base()" << endl;
    }

  private:
    int _ib;
};

class D
    : Base
{
  public:
    D()
        : Base()
    {
        cout << "D()" << endl;
    }

    // D(int id)
    // : Base()
    // , _id(id)
    // {
    //      cout<<"D"<<endl;
    // }
    // private:
    //     int _id;
};

int main()
{
    D a;
}
// 派生类没有显式定义构造函数，但基类有显式定义构造函数
// 则创建派生类对象时，会自动调用基类的默认构造函数, 此时
// 基类必须提供一个默认构造函数

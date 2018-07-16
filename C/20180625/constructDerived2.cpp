#include <iostream>
using namespace std;
class Base{
    public: 
        Base() {
            cout<<"Base"<<endl;
        }
};

class D
: Base
{
    public:
    D(int id)
    : Base()
    , _id(id)
    {
       cout<<"D"<<endl;
    }
    private:
        int _id;
}; 

int main(){
    D a(1);
}
// 派生类有显式定义构造函数，但基类没有显式定义构造函数
// 则创建派生类对象时，会自动调用基类的默认构造函数

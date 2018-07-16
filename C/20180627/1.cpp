#include <iostream>
using namespace std;
class B {
    public: 
        B(long B)
        : _B(B)
        {
           cout<<"B\n";
        }
        virtual void  a(){cout<<"B::A\n";}
        virtual void  b(){cout<<"B::B\n";}
        virtual void  c(){cout<<"B::C\n";}
    private: 
        long _B;
};

class D
:public B
 {
    public: 
        D(long Base, long D) 
        : B(Base)
        , _D(D){
            cout<<"D\n";
        }
        virtual void  a(){cout<<"D::A\n";}
        virtual void  b(){cout<<"D::B\n";}
        virtual void  c(){cout<<"D::C\n";}
    private: 
        long _D;
};
//虚函数表就是一个二级指针
int main() {
    D d(10, 100);
    long **p = (long**) &d; 
    typedef void (* Fun)();
    Fun f1 = (Fun)p[0][1];
    f1();
    cout<<(long)p[1]<<" "<<(long)p[2];

}
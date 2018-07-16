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

int main() {
    D d(10, 100);
}
#include <iostream>

using namespace std;

template <class T>
T add1 (T x, T y) {
    return x + y;
}

template <typename T, int k = 5>
T add (T x, T y) {
   
    return x + y ;
}

template <typename T, typename... Args>//模板参数包
void print(T t, Args... args) //函数参数包
{
    cout<< t <<endl;
   
    cout << "sizeof...(args)"<<sizeof...(args)<<endl;
    cout << "sizeof...(Args)"<<sizeof...(Args)<<endl;
}
void plane() {
    cout << endl;
}
template <typename T, typename... Args>
void plane(T t, Args... args)
{
    cout<< t <<endl;
    plane(args...);
}

int main () {
    // char a = 'a' ,b = 1;
    // cout<< add(a,b)<<endl;
    int b2 = 1;
    int c = 2;
    char c2 = 'a';
    plane(b2,c, c2);
    print(b2,c,c);    
}
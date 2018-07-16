/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：singleton.cpp
*   Creator    ：Max
*   Date       ：2018/06/10
*   Description：
*
================================================================*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack
{
  private:
    int _top;
    int _size;
    T *_array;

  public:
    Stack(int sz = 100)
    {
        _size = sz;
        _top = 0;
        _array = new T[_size];
    }
    ~Stack()
    {
        delete[] _array;
    }
    void clear()
    {
        _top = 0;
    }
    bool push(const T &it)
    {
        if (_top == _size)
            return false;
        else
        {
            _array[_top++] = it;
            return true;
        }
    }
    bool pop()
    {
        if (_top == 0)
            return false;
        else
        {
           --_top;
            return true;
        }
    }
    T top()
    {
        if (_top == 0)
            return -1;
        else
        {
            T it;
            it = _array[_top - 1];
            return it;
        }
    }
    int length() const
    {
        return top;
    }
};

int main() {
    Stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    std::cout<<a.top();
    a.pop();
    std::cout<<a.top();

}
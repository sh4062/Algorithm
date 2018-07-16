/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：singleton.cpp
*   Creator    ：Max
*   Date       ：2018/06/10
*   Description：
*
================================================================*/
template <class T>
class Queue
{
  private:
    int _front;
    int _rear;
    int _size;
    T* _array;
  public:
    Queue(int sz = 100) {
        _size = sz + 1;
        _rear = 0;
        _front = 1;
        _array = new T[_size];
    }
    ~Queue(){delete [] _array;}
    void clear() {
        _front = _rear;
    }

    bool enqueue(const T &it) {
        if((_rear + 2) % _size == _front) return false;
        _rear = (_rear + 1) % _size;
        _array[_rear] = it;
        return true;
    }

    bool dequeue(T & it) {
        if(length() == 0) return false;
        it = _array[_front];
        _front = (_front + 1) %_size;
        return true;
    }   

    virtual int length() const {
        return ((_rear + _size) - _front + 1) % _size;
    } 
};
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class Vector
{
  public:
    typedef T *iterator;
    typedef const T *const_iterator;

    Vector()
        : _start(0), _finish(0), _end_of_storage(0)
    {
    }

    ~Vector();

    iterator begin() { return _start; }
    iterator end() { return _finish; }

    void push_back(const T &t);
    void pop_back();

    size_t size() const
    {
        return _finish - _start;
    }

    size_t capacity() const
    {
        return _end_of_storage - _start;
    }

  private:
    void reallocate();

  private:
    static allocator<T> _alloc;
    T *_start;
    T *_finish;
    T *_end_of_storage;
};

template <typename T>
Vector<T>::~Vector()
{
    while (_start != _finish)
        _alloc.destroy(--_finish);
    if (_start)
        _alloc.deallocate(_start, capacity());
}

template <typename T>
void Vector<T>::push_back(const T &t)
{
    if (size() == capacity())
    {
        reallocate();
    }
    _alloc.construct(_finish++, t);
}

template <typename T>
void Vector<T>::pop_back()
{
    if (_start != _finish)
    {
        _alloc.destroy(--_finish);
    }
}

template <typename T>
void Vector<T>::reallocate()
{
    size_t oldCapacity = capacity();
    size_t newCapacity = oldCapacity ? 1.5 * oldCapacity : 1;

    T *tmp = _alloc.allocate(newCapacity); //申请是原始的内存
    if (_start)
    {
        ///memcpy();// 内置类型的数据
        //copy();//调用对象的赋值运算符函数,意味着对象存在
        std::uninitialized_copy(_start, _finish, tmp); //复制原来空间的数据

        //回收原来空间的数据
        while (_start != _finish)
            _alloc.destroy(--_finish);
        //回收原来空间
        _alloc.deallocate(_start, oldCapacity);
    }
    _start = tmp;
    _finish = _start + oldCapacity;
    _end_of_storage = _start + newCapacity;
}
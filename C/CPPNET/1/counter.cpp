/*
 * File: counter.cpp
 * Project: 1
 * File Created: Wednesday, 4th July 2018 4:17:56 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 4:17:58 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "mutex.h"
#include<boost/noncopyable.hpp>
class Counter:boost::noncopyable 
{
    public:
        Counter():value_(0) {}
        int64_t value() const;
        int64_t getAndIncrease();
        private:
        int64_t value_;
        mutable MutexLock mutex_;

};

int64_t Counter::value() const {
    MutexLockGuard lock(mutex_);
    return value_;
}

int64_t Counter::getAndIncrease(){
    MutexLockGuard lock(mutex_);
    int64_t ret = value_++;
    return ret;
}
//对象构建线程安全：不泄漏this指针
//回调函数就是一个通过函数指针调用的函数。
//因为可以把调用者与被调用者分开，所以调用者不关心谁是被调用者。它只需知道存在一个具有特定原型和限制条件的被调用函数。
//简而言之，回调函数就是允许用户把需要调用的函数的指针作为参数传递给一个函数，以便该函数在处理相似事件的时候可以灵活的使用不同的方法。
//正确的做法：
// class Observer{};//以后再说
// class Foo:public Observer{
//     public:
//         Foo();
//         virtual void update();
//         //另外注册一个函数，在构造后执行回调函数的注册
//         void observer(Observer*s) {
//             s->register_(this);
//         }

// };
//二段构造 构造+init 
//多线程析构很难
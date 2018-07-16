/*
 * File: thread.cpp
 * Project: thread
 * File Created: Wednesday, 4th July 2018 2:14:39 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 2:14:41 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "thread.h"
using namespace oh;

Thread::Thread(ThreadCallback && cb)
:_cb(std::move(cb)) 
,_isRunning(false)
,_pthid(0)
{

}

Thread::~Thread(){
    if(_isRunning) {
        pthread_detach(_pthid);
    }
    _isRunning = false;

}
void Thread::start() {
    pthread_create(&_pthid, NULL, threadFunc,this);
    _isRunning = true;
}

void* Thread::threadFunc(void* args) {
    Thread* pthread = static_cast<Thread*> (args);
    if(pthread) pthread->_cb();
    return NULL; 
}

void Thread::join() {
    pthread_join(_pthid, NULL);
    _isRunning = false;
    
}



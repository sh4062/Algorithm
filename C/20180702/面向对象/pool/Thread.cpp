/*
 * File: Thread,cpp
 * Project: pool
 * File Created: Wednesday, 4th July 2018 9:54:28 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 9:54:30 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "Thread.h"
using namespace oh;

Thread::Thread()
    : _thread(0), _isRunning(false)
{
}

Thread::~Thread()
{
    if (_isRunning)
    {
        pthread_detach(_thread);
        _isRunning = false;
    }
}

void Thread::start()
{
    pthread_create(&_thread, NULL, threadFunc, this);
    _isRunning = true;
}

void *Thread::threadFunc(void *args)
{
    Thread *pthread = static_cast<Thread *>(args);
    if (pthread)
        pthread->run();
    return NULL;
}

void Thread::join()
{
    pthread_join(_thread, NULL);
    _isRunning = false;
}

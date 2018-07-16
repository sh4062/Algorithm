/*
 * File: Threadpool.cpp
 * Project: pool
 * File Created: Wednesday, 4th July 2018 10:14:41 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 10:14:42 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "Threadpool.h"
#include "WorkerThread.h"
#include <unistd.h>

using namespace oh;

void Threadpool::start()
{
    for (size_t idx = 0; idx < _threadNum; ++idx)
    {
        shared_ptr<Thread> pThread(new WorkerThread(*this));
        _threads.push_back(std::move(pThread));
    }
    for (auto &pThread : _threads)
    {
        pThread->start();
    }
}

void Threadpool::stop()
{
    if (!_isExit)
    {
        while(!_taskQue.empty()){
            sleep(1);
        }
        _isExit = true;
        cout<< "Threadpool Stop\n";
        for (auto &pThread : _threads)
        {
            pThread->join();
        }
    }
}

Threadpool::~Threadpool()
{
    if (!_isExit)
    {
        stop();
    }
}

void Threadpool::addTask(Task *ptask)
{
    _taskQue.push(ptask);
}

Task *Threadpool::getTask()
{
    return _taskQue.pop();
}

//子线程要做的事情
void Threadpool::threadFunc()
{
    while (!_isExit)
    {
        Task *ptask = getTask();
        if (ptask)
            ptask->process();
    }
}
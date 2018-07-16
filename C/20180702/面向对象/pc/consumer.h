/*
 * File: consumer.h
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 8:37:50 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 8:37:53 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_CONSUMER_H_
#define _OH_CONSUMER_H_
#include "thread.h"
#include "TaskQueue.h"
namespace oh
{
    class Consumer
    : public Thread
    {
        public: 
        Consumer(TaskQueue & tq)    
        : _tq(tq){}
        private: 
        void run();
        TaskQueue & _tq;

    };
}

#endif
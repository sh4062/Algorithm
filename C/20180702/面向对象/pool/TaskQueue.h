/*
 * File: TaskQueue.h
 * Project: pool
 * File Created: Wednesday, 4th July 2018 10:04:29 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 10:04:31 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_TASK_QUEUE_H_
#define _OH_TASK_QUEUE_H_
#include "mutex.h"
#include "Condition.h"
#include <queue>
using namespace std;
using namespace oh;

namespace oh {
    class Task;

    class TaskQueue {
        public:
            TaskQueue(size_t queSize)
            : _queue_size(queSize)
            , _mutex()
            , _notEmpty(_mutex)
            , _notFull(_mutex)
            {}

            void push(Task*);
            Task* pop();
            bool empty() {
                return _queue.size() == 0;
            }
            bool full() {
                return _queue.size() == _queue_size;
            }
        private:    
            size_t _queue_size;
            queue<Task*> _queue;
            MutexLock _mutex;
            Condition _notFull;
            Condition _notEmpty;

    };
}
#endif
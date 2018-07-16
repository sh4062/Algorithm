/*
 * File: Thread.h
 * Project: pool
 * File Created: Wednesday, 4th July 2018 9:49:13 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 9:49:14 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_THREAD_H_
#define _OH_THREAD_H_
#include <pthread.h>
namespace oh{
    class Thread {
        public:
            Thread();
            virtual ~Thread();
            void start();
            void join();
            bool isRunning() const {
                return _isRunning;
            }
        private: 
            virtual void run() = 0;
            static void * threadFunc(void*);
        private:    
            pthread_t _thread;
            bool _isRunning;

    };
}
#endif

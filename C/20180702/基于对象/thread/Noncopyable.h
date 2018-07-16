/*
 * File: Noncopyable.h
 * Project: thread
 * File Created: Wednesday, 4th July 2018 2:17:41 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 2:17:54 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_NC_H
#define _OH_NC_H

namespace oh {
    class Noncopyable{
        protected:
           Noncopyable(){};
           ~Noncopyable(){};
        private: 
           Noncopyable(const Noncopyable&);
           Noncopyable & operator = (const Noncopyable &);
    };
}
#endif
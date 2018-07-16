/*
 * File: Nocopyable.h
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 11:35:25 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 11:35:38 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef __OH_NONCOPYABLE_H__
#define __OH_NONCOPYABLE_H__


namespace oh
{

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable&);
	Noncopyable & operator=(const Noncopyable &);
};

}//end of namespace oh

#endif
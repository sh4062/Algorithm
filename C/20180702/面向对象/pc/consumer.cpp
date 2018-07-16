/*
 * File: consumer.cpp
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 9:19:01 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 9:19:02 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "consumer.h"

#include <unistd.h>
#include <iostream>
using namespace std;
using namespace oh;
 

void Consumer::run()
{
	while(true)
	{
		int number = _tq.pop();
		cout << ">>> Consumer consumes a number: " << number << endl;
		::sleep(2);
	}
}
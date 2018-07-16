/*
 * File: producer.cpp
 * Project: pc
 * File Created: Tuesday, 3rd July 2018 9:27:32 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Tuesday, 3rd July 2018 9:27:39 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include "producer.h"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace oh;
using namespace std;

void Producer::run()
{
	::srand(::time(NULL));
	while(true)
	{
		int number = ::rand() % 100;
		_tq.push(number);
		cout << ">> produce a number: " << number << endl;
		::sleep(1);
	}
}
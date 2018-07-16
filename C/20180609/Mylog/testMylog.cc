 ///
 /// @file    testMylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 15:25:09
 ///
 
#include "Mylog.h"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;



void test0()
{
	wd::Mylog::getInstance()->warn("this is warn msg");
	wd::Mylog::getInstance()->info("this is ifno msg");
	wd::Mylog::getInstance()->error("this is error msg");
	wd::Mylog::getInstance()->debug("this is debug msg");
}

void test1()
{
	cout << __FILE__ << endl
		 << __LINE__ << endl
		 << __FUNCTION__ << endl;
}

void test2()
{
	wd::Mylog::getInstance()->warn(prefix("this is warn msg"));
	wd::Mylog::getInstance()->info(prefix("this is ifno msg"));
	wd::Mylog::getInstance()->error(prefix("this is error msg"));
	wd::Mylog::getInstance()->debug(prefix("this is debug msg"));
}

void test3()
{
	LogWarn("this is warn msg");
	LogInfo("this is info msg");
	LogError("this is error msg");
	LogDebug("this is debug msg");
}
 
int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();

	return 0;
}

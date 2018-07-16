 ///
 /// @file    log4cpp2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 14:47:13
 ///
 

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>

#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using namespace log4cpp;

 
int main(void)
{
	PatternLayout * ptnLayout1 = new PatternLayout();
	ptnLayout1->setConversionPattern("%d [%p] %m %n");

	PatternLayout * ptnLayout2 = new PatternLayout();
	ptnLayout2->setConversionPattern("%d [%p] %m %n");

	FileAppender * fileAppender = new FileAppender("fileAppender", "wangdao.txt");
	fileAppender->setLayout(ptnLayout1);

	RollingFileAppender * rollingFileAppender 
		= new RollingFileAppender("rollingFileAppender", "rollwangdao.txt", 5 * 1024);
	rollingFileAppender->setLayout(ptnLayout2);

	Category & root = Category::getRoot().getInstance("root");
	root.addAppender(fileAppender);
	root.addAppender(rollingFileAppender);
	root.setPriority(Priority::DEBUG);

	for(int idx = 0; idx != 100; ++idx)
	{
		std::ostringstream oss;
		oss << "this is " << idx << " line message";
		root.error(oss.str());
	}
	Category::shutdown();
	return 0;
}

 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class String 
{
public:
	String()
	:_pstr(new char[1]())
	{}

	String(const char * pstr)
	:_pstr(new char[strlen(pstr) + 1]())
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr,pstr);
	}

	//复制构造函数
	String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr) + 1]())
	{
		cout << "String(const String & rhs)" << endl;
		strcpy(_pstr,rhs._pstr);
	}

	//移动构造函数 C++11
	String(String && rhs)
	:_pstr(rhs._pstr)
	{
		cout << "String(String && rhs)" << endl;
		rhs._pstr = NULL;
	}
	
	//移动赋值运算符函数
	String & operator=(String && rhs)
	{
		cout << "String & operator=(String &&)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = rhs._pstr;
			rhs._pstr = NULL;
		}
		return *this;
	}

	//赋值运算符函数
	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String&)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr,rhs._pstr);
		}
		return *this;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}

	const char * c_str() const
	{
		return _pstr;
	}

	friend std::ostream & operator<<(std::ostream & os,const String & rhs);
private:
	char * _pstr;
};
std::ostream & operator<<(std::ostream & os,const String & rhs)
{
	os << rhs._pstr;
	return os;
}

int test0(void)
{
	String s1("hello,world");
	cout << "s1 = " << s1 << endl;

	s1 = String("shenzhen");
	cout << "s1 = " << s1 << endl;
	printf("s1's address = %p\n",s1.c_str());
	cout << endl;

	String s2("wangdao");
	cout << "s2 = " << s2 << endl;
	s2 = std::move(s1);//显式的将一个左值转换成右值来使用
	cout << "s2 = " << s2 << endl;
	printf("s2's address = %p\n",s2.c_str());

	cout << "s1 = " << s1 << endl;

	cout << "......." << endl;
	
	return 0;
}

int main(void)
{
	test0();
	return 0;
}
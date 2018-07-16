#include <iostream>
#include <cstring>
#include <assert.h>
#include "stdlib.h"
class String
{
public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
    unsigned long int size();
	~String();
	void print();

private:
	char * _pstr;
    int _length;
};
 ///
 /// @file    testDictionary.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 11:49:41
 ///
 
#include "Dictionary.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Dictionary dictionary;
	dictionary.read("b.txt");
	dictionary.store("dictionary.txt");

	return 0;
}

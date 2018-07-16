 ///
 /// @file    Dictionary.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 11:24:38
 ///
 
#include "Dictionary.h" // 如果分成头文件和实现文件，则实现文件的第一行必须要是相应的头文件

//#include "xxx.h"      // 自定义头文件放在系统头文件之上

#include <string.h>     //C的头文件放在C++头文件的前面

#include <iostream> 
#include <fstream>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
 

void Dictionary::read(const string & filename)
{
	ifstream ifs(filename);
	//ifstream ifs2(ifs);//IO流对象都是不能进行复制的
	if(!ifs) {
		cout << "ifstream open error!" << endl;
		return;
	}

	string line;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		string word;
		while(iss >> word)
		{
			processWord(word);
		}
	}
	ifs.close();

	//C++的排序算法
	std::sort(_dictionary.begin(), _dictionary.end());
}


void Dictionary::store(const string & filename)
{
	ofstream ofs(filename);
	if(!ofs){
		cout << "ofstream open error!" << endl;
		return;
	}

	for(auto & record : _dictionary)
	{
		ofs << record._word << endl;//<< " " << record._freq 
	}
	ofs.close();
}

void Dictionary::processWord(const string & word)
{
	for(auto & ch : word)
	{
		if(!isalpha(ch))
			return;
	}
	size_t cnt = 0;
	for(auto & record : _dictionary)
	{
		if(record._word == word)
		{
			++record._freq;
			break;
		}
		++cnt;
	}
	if(cnt >= _dictionary.size())
	{
		_dictionary.push_back(Record(word, 1));
	}
}


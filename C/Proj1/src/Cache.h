/*
 * File: Cache.h
 * Project: src
 * File Created: Monday, 9th July 2018 11:24:00 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Friday, 13th July 2018 3:08:26 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#ifndef _OH_CACHE_H_
#define _OH_CACHE_H_
#include <unordered_map>
#include <string>
#include <fstream>
using namespace std;

namespace oh
{
class Cache
{
  public:
    Cache(int num = 10)
    {
        _hashMap.reserve(num);
    };
    Cache(const Cache &cache)
    {
        _hashMap.reserve(cache._hashMap.size());
        for (auto &it : cache._hashMap)
        {
            _hashMap[it.first] = it.second;
        }
    };
    void addElement(const string &key, const string &value)
    {
        _hashMap[key] = value;
    };
    void readFromFile(const string &filename)
    {
        ifstream ofs(filename);
        string tmp1;
        string tmp2;
        while (!ofs.eof())
        {
            ofs >> tmp1;
            ofs >> tmp2;
            _hashMap[tmp1] = tmp2;
        }
    };
    void writeToFile(const string &filename)
    {
        ofstream ofs(filename);
        for (auto &it : _hashMap)
        {
            ofs << it.first << " " << it.second << endl;
        }
    };
    void update(const Cache &rhs)
    {
       // this->writeToFile();
    };
    unordered_map<string, string> _hashMap;
  private:
    
};
} // namespace oh
#endif
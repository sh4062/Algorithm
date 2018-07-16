#ifndef _OH_MY_DICT_H_
#define _OH_MY_DICT_H_
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include "assert.h"
#include "stdio.h"
#include "pthread.h"
using namespace std;
namespace oh
{
class MyDict
{
  public:
    static MyDict *createInstance()
    {
        pthread_once(&_po, init);
        return _MyDict;
    }
    static void init()
    {

        _MyDict = new MyDict();

        atexit(destroy); //作用是注册函数 当进程结束时调用 注册几次 执行几次
    }
    void init0(const char *dictEnPath = "./dict.dict", const char *dictCnPath = NULL)
    {

        ifstream infile;
        infile.open(dictEnPath); //将文件流对象与文件连接起来

        assert(infile.is_open()); //若失败,则输出错误消息,并终止程序运行

        string s;
        int i;

        while (!infile.eof())
        {
            infile >> s;
            infile >> i;
            _dict.push_back(pair<string, int>(s, i));
        }
        infile.close();
        vector<string> alpha = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
                                "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
        vector<string> alpha_u = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                                  "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

        for (int j = 0; j < _dict.size(); j++)
        {
            for (auto l : alpha)
            {
                if (_dict[j].first.find(l) != std::string::npos)
                {
                    _index_table[l].insert(j);
                }
            }
            for (auto l : alpha_u)
            {
                if (_dict[j].first.find(l) != std::string::npos)
                {
                    _index_table[l].insert(j);
                }
            }
        }
    }
    void store_en_dict(const string en_index)
    {
        ofstream c(en_index);
        for (auto &i : _index_table)
        {
            c << i.first << " ";
            for (auto &ii : i.second)
            {
                c << ii << " ";
            }
            c << endl;
        }
        c.close();
    };  
    static void destroy()
    {
        if (_MyDict)
        {
            delete _MyDict;
        }
    }
    static vector<pair<string, int>> _dict;
    static map<string, set<int>> _index_table;

  private:
    MyDict()
    {
        cout << "MyDict\n";
    }
    ~MyDict() { cout << "~MyDict\n"; }

    static MyDict *_MyDict;
    static pthread_once_t _po;
};
} // namespace oh

#endif

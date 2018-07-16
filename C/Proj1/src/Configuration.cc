#include "Configuration.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace oh;
Configuration::Configuration(const string &filepath)
    : _filepath(filepath)
{
    map<string, string> configMap;
    ifstream infile;
    infile.open(filepath.data()); //将文件流对象与文件连接起来
    assert(infile.is_open());     //若失败,则输出错误消息,并终止程序运行

    string s;
    getline(infile,s);
    configMap["1"]=s;
    getline(infile,s);
    configMap["2"]=s;
    getline(infile,s);
    configMap["threadNum"]=s;
    getline(infile,s);
    configMap["queSize"]=s;
    getline(infile,s);
    configMap["ip"]=s;
    getline(infile,s);
    configMap["port"]=s;
    infile.close(); //关闭文件输入流
    _configMap = configMap;
}

map<string, string> &Configuration::getConfigMap()
{
    // for (auto &i : _configMap)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    return _configMap;
}
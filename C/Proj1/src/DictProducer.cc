
#include "DictProducer.h"
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <string.h>
#include "stdlib.h"
#include "stdio.h"
using namespace std;
using namespace oh;

DictProducer::DictProducer(const string &dir)
:_dir(dir)
{
    DIR *dir0;
    struct dirent *ptr;
    char *flow[1024];
    int num = 0, i = 0;

    if ((dir0 = opendir(_dir.c_str())) == NULL)
    {
        cerr << "Open dir error..." << endl;
        return;
    }
    // readdir() return next enter point of directory dir
    while ((ptr = readdir(dir0)) != NULL)
    {
        flow[num] = (char *)malloc(sizeof(char));
        strcpy(flow[num], ptr->d_name);
        num++;
    }

    for (i = 0; i < num; i++)
    {
        if(strcmp(flow[i],".")!=0&&strcmp(flow[i],"..")!=0){
        char tmp[64];
        bzero(&tmp,64);
        sprintf(tmp,"%s/%s",_dir.c_str(),flow[i]);
        cout << tmp << endl;
        _files.push_back(string(tmp));}
    }
    closedir(dir0);
}
//创建英文字典
void DictProducer::build_en_dict()
{
    ifstream file(_files[0]);
    string s;
    while (file >> s)
    {

        if ((!isalpha(s[0])) || (!isalpha(s[s.size() - 1])))
        {
            continue;
        }
        std::map<string, int>::iterator it;
        it = _dict.find(s);
        if (it == _dict.end())
        {
            _dict.insert(pair<string, int>(s, 1));
        }
        else
        {
            it->second++;
        }
    }
    file.close();
}
//将词典写入文件
void DictProducer::store_dict(const char *filepath)
{
    ofstream file(filepath);
    for (auto i : _dict)
    {
        file << i.first << " " << i.second << endl;

        // cout << i.first << " " << i.second << endl;
    }
    file.close();
}
//查看文件路径，作为测试用
void DictProducer::show_files() const
{
    for (auto &i : _files)
        cout << i << endl;
}
//查看词典，作为测试用
void DictProducer::show_dict() const
{
    for (auto &i : _dict)
        cout << i.first <<" "<<i.second << endl;
}
//存储某个单词
void DictProducer::push_dict(const string &word)
{
    std::map<string, int>::iterator it;
    it = _dict.find(word);
    if (it == _dict.end())
    {
        _dict.insert(pair<string, int>(word, 1));
    }
    else
    {
        it->second++;
    }
}
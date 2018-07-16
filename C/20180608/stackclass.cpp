/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：stackclass.cpp
*   Creator    ：Max
*   Date       ：2018/06/10
*   Description：
*
================================================================*/
//只在栈上创建对象：将new/delete私有化
#include <stdio.h>
#include <cstring>
class Tank
{
  public:
    Tank(int id, const char*name):
    _id(id),_name(new char[strlen(name) + 1]())
    {
        strcpy(_name, name);
    }
    ~Tank()
    {
       delete [](_name);
    }

  private:
    void *operator new(size_t size);
    void operator delete(void *ret);

  private:
    char * _name;
    int _id;
};

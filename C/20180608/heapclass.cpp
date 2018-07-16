/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：heapclass.cpp
*   Creator    ：Max
*   Date       ：2018/06/11
*   Description：
*
================================================================*/

//只在堆上创建对象：将析构函数私有化并且定义destroy
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
class Tank
{
  public:
    Tank(int id, const char*name):
    _id(id),_name(new char[strlen(name) + 1]())
    {
        strcpy(_name, name);
    }
    void Destroy(){
        delete this;
    }
  public:
      void *  operator  new (size_t sz) {
        void * ret = malloc(sz);
        return ret;
    }

    void  operator delete(void * ret) {
        free(ret);
    }
    
  private:
    char * _name;
    int _id;
    ~Tank()
    {
       delete [](_name);
    }

};

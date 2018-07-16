/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：computer.cpp
*   Creator    ：Max
*   Date       ：2018/06/10
*   Description：
*
================================================================*/

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

//Class 
class Computer
{
public:
  Computer(const char * brand, double price)
  :_brand(new char[strlen(brand) + 1]())
  ,_price(price)
  {
      cout << "Computer(const char*, float)" << endl;
      strcpy(_brand, brand);
      _totalPrice += _price;
  }

  Computer(const Computer &rhs)//Copy constructor
  : _brand(new char[strlen(rhs._brand) + 1]())
  , _price(rhs._price)
  {
    strcpy(_brand, rhs._brand);
    cout << "Computer(const Computer&)"<<endl;
  }
  //系统自带的只执行了浅拷贝
  //赋值重载
  Computer & operator=(const Computer & rhs)
  {
    if(this != &rhs)//自复制
    {
      delete [] _brand;
      _brand = new char[strlen(rhs._brand) + 1]();
      strcpy(_brand, rhs._brand);
      _price = rhs._price;
    }
    return *this;
  }
  void print(){
    cout<<"brand:"<<_brand<<endl;
    cout<<"price"<<_price <<endl;
  }
  void printTP(){
    cout<<"TotalPrice"<<_totalPrice<<endl;
  }
  ~Computer(){
    delete [] _brand;
    _brand = NULL;
    cout<< "~Computer"<<endl;
  }
private:
  char* _brand;
  double _price;
  static double _totalPrice;
};

//静态成员需要在类外初始化！
double Computer::_totalPrice = 0;

int main(){
  Computer com1("MSI",11111);
  Computer com2("Apple", 22222);
  com1.print();
  com2.print();
  com1.printTP();
  com2.printTP();
}

  

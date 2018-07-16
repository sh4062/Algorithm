#include "String.h"
String::String() : _pstr(nullptr), _length(0)
{
    _pstr = new char[1];
    _pstr[0] = '\0';
}
//构造函数
String::String(const char *pstr)
{
    if (pstr == nullptr)
    {
        _pstr = new char[1];
        _pstr[0] = '\0';
        _length = 0;
    }
    else
    {
        _length = strlen(pstr);
        _pstr = new char[_length + 1];
        strcpy(_pstr, pstr);
    }
}
//拷贝构造函数
String::String(const String &rhs)
{
    int length = strlen(rhs._pstr);
    if (length == 0)
    {
        _pstr = new char[1];
        _pstr[0] = '\0';
        _length = 0;
    }
    else
    {
        _length = strlen(rhs._pstr);
        _pstr = new char[_length + 1];
        strcpy(_pstr, rhs._pstr);
    }
}
//析构函数
String::~String()
{
    delete[] _pstr;
}
//=c
String &String::operator=(const String &rhs)
{
    if (&rhs != this)
    {
        delete[] _pstr;
        _length = rhs._length;
        _pstr = new char[_length + 1];
        assert(_pstr != 0);
        strcpy(_pstr, rhs._pstr);
    }
    else
    {
        std::cout << "Can not assign string to itself!" << std::endl;
    }
    return *this;
}
//print
void String::print()
{
    printf("%s\n", _pstr);
}
//返回大小
unsigned long int String::size()
{
    return _length;
}
//test
int main(void)
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();
    str3.print();

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();
    system("sleep 3");
    return 0;
}
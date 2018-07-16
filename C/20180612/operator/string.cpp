#include "string.h"
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
    unsigned long length = strlen(rhs._pstr);
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
//print
void String::print()
{
    printf("%s\n", _pstr);
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

//=c
String &String::operator=(const char *rhs)
{
    if (rhs != *this)
    {
        delete[] _pstr;
        _length = strlen(rhs);
        _pstr = new char[_length + 1];
        assert(_pstr != 0);
        strcpy(_pstr, rhs);
    }
    else
    {
        std::cout << "Can not assign string to itself!" << std::endl;
    }
    return *this;
}
//+=s
String &String::operator+=(const String &s2)
{
    *this = *this + s2;
    return *this;
}
//+=c
String &String::operator+=(const char *s2)
{
    *this = *this + s2;
    return *this;
}
//[]
char &String::operator[](std::size_t index)
{
    if (index >= 0 && index < _length)
        return _pstr[index];
    else
        std::cout << "???" << std::endl;
}
//[]c
const char &String::operator[](std::size_t index) const
{
    if (index >= 0 && index < _length)
        return _pstr[index];
    else
        std::cout << "???" << std::endl;
}
//size_t
std::size_t String::size() const
{
    return this->_length;
}
//cstr
const char *String::c_str() const
{
    return this->_pstr;
}

//==
bool operator==(const String &a, const String &b)
{
    if (strcmp(a._pstr, b._pstr) == 0)
    {
        return true;
    }
    return false;
}
//!=
bool operator!=(const String &a, const String &b)
{
    if (strcmp(a._pstr, b._pstr) == 0)
    {
        return false;
    }
    return true;
}

//<
bool operator<(const String &a, const String &b)
{
    if (strcmp(a._pstr, b._pstr) < 0)
    {
        return true;
    }
    return false;
}

//>
bool operator>(const String &a, const String &b)
{
    if (strcmp(a._pstr, b._pstr) > 0)
    {
        return true;
    }
    return false;
}

//<
bool operator<=(const String &a, const String &b)
{
    if (strcmp(a._pstr, b._pstr) <= 0)
    {
        return true;
    }
    return false;
}

//>=
bool operator>=(const String &a, const String &b)
{
    if (strcmp(a._pstr, b._pstr) >= 0)
    {
        return true;
    }
    return false;
}
//
std::ostream &operator<<(std::ostream &os, const String &s)
{
    os << s._pstr;
    return os;
}
std::istream &operator>>(std::istream &is, String &s)
{   
    is >> s._pstr;
    return is;
}
//
String operator+(const String &a, const String &b)
{
    char *s = new char[a.size() + b.size() + 1];
    std::cout << "!1\n";
    strcpy(s, a.c_str());
    std::cout << "!2\n";
    strcat(s, b.c_str());
    std::cout << "3!\n";
    String str(s);
    std::cout << "4!\n";
    return str;
}
String operator+(const String &a, const char *b)
{
    char *s = new char[a.size() + strlen(b) + 1];
    strcpy(s, a.c_str());
    strcat(s, b);
    String str(s);
    return str;
}
String operator+(const char *b, const String &a)
{
    char *s = new char[a.size() + strlen(b) + 1];
    strcpy(s, a.c_str());
    strcat(s, b);
    String str(s);
    return str;
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
    char a[10] = "aaaaa";
    str4 = a;
    str4.print();
    char *b = "bbbbbb";
    str4 = a;
    str4.print();
    std::cout << (str4 > str3) << std::endl;
    std::cout << (str4 < str3) << std::endl;
    std::cout << str4 + str3 << std::endl;
    //std::cout << (str4 ) << std::endl;
    system("sleep 3");

    return 0;
}
#include "stdio.h"
#include "string.h"
#include <iostream>
using namespace std;

class String
{
     class Charproxy
    {
      public:
        Charproxy(size_t idx, String &self)
            : _idx(idx), _self(self)
        {
        }

        Charproxy & operator = (const char &x);
        friend ostream  & operator<<(ostream &os, const Charproxy &x);

      private:
        size_t _idx;
        String &_self;
    };
  friend class Charproxy;
  public:
    String(const char *str = "")
        : _str(new char[strlen(str) + 5])
    {
        _str += 4;
        strcpy(_str, str);
        _GetRefCount(_str) = 1; //初始化引用计数
    }
    String(String &s)
        : _str(s._str)
    {
        ++_GetRefCount(_str);
    }
    String &operator=(const String &s)
    {
        if (this != &s)
        {
            this->~String();
            _str = s._str;
            ++_GetRefCount(_str);
        }
        return *this;
    }
    Charproxy operator[](size_t index)
    {
        return Charproxy(index, *this);
        
    }
    // char &operator[](size_t index)
    // {
    //     if (index < size())
    //     {
    //         if (_GetRefCount(_str) > 1)
    //         {
    //             _Release();
    //             char *tmp = new char[strlen(_str) + 5];
    //             tmp += 4;
    //             strcpy(tmp, _str);
    //             _GetRefCount(_str) = 1;
    //             _str = tmp;
    //         }
    //         return _str[index];
    //     }
    //     else
    //     {
    //         static char null = '\0';
    //         return null;
    //     }
    // }
    size_t size() const { return strlen(_str); }
    ~String()
    {
        _Release();
    }

  private:
    int &_GetRefCount(char *ptr)
    {
        return *(int *)(ptr - 4);
    }
    void _Release()
    {
        if (--_GetRefCount(_str) == 0)
        {
            delete[](_str - 4);
            cout << "delete" << endl;
        }
    }
    friend ostream &operator<<(ostream &os, const String &s)
    {
        os << s._str;
        return os;
    }
    friend ostream &operator<<(ostream &os, const Charproxy &C)
    {
        os << C._self._str[C._idx];
        return os;
    }

  private:
    char *_str;
};
String::Charproxy &String::Charproxy::operator =(const char &c)
{
    if (_idx < _self.size())
    {
        {
            if (_self._GetRefCount(_self._str) > 1)
            {
                _self._Release();
                char *tmp = new char[strlen(_self._str) + 5];
                tmp += 4;
                strcpy(tmp, _self._str);
                _self._GetRefCount(_self._str) = 1;
                _self._str = tmp;
            }
            _self._str[_idx] = c;
        }

        return *this;
    }
}
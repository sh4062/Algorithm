//左旋转字符串
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n==0||n==str.size()||str.size()==0)return str;
        n = n%str.size();
        string l = str.substr(0,n);
        string r = str.substr(n,str.size()-n);
        return r+l;
    }
};
//答案原理：YX = (XTYT)T

class Solution {
public:
    string LeftRotateString(string str, int n) 
    {
      int len = str.size();
        if(len == 0) return str;
        n %= len;
        for(int i = 0, j = n - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = n, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = 0, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        return str;
    }
};
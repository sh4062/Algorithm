#include <iostream>  
#include <string>  
#include <stack>  
#include <cstdlib>
#include <fstream>  
using namespace std;  
  
bool isone(char c){  
    return (c=='+' || c=='-');  
}  
bool istwo(char c){  
    return (c=='*' || c=='/');  
}  
  
  
string shorten(string m){  
    stack<char> s;  
    string sur;  
    int i;  
    char w;  
    sur;  
      
    for(i=0;i<m.size();i++){  
        if(isdigit(m[i]) || m[i]=='.'){  
            while(isdigit(m[i]) || m[i]=='.')   sur += m[i++];  
            i--;  
            sur += '$';  
        }  
        else if(isone(m[i])){  
            while(s.size() && (isone(s.top()) || istwo(s.top()))){  
                sur+=s.top();  
                s.pop();  
            }  
            s.push(m[i]);  
        }  
        else if(m[i]==')'){  
            while(s.top()!='('){  
                sur+=s.top();  
                s.pop();  
            }  
            s.pop();  
        }  
        else if(istwo(m[i])){  
            while(s.size() &&  istwo(s.top())){  
                sur+=s.top();  
                s.pop();  
            }  
            s.push(m[i]);  
        }  
        else s.push(m[i]);  
    }  
    while(s.size()){  
        sur+=s.top();  
        s.pop();  
    }  
    return sur;  
}  
  
double tentimes(int n){  
    double res=1;  
    for(int i=0;i<n;i++){  
        res *= 10;  
    }  
    return res;  
}  
  
double str2double(string s){  
    double res=0;  
    char c;  
    int dec=0;  
    for(int i=1;i<=s.size();i++){  
        c=s[i-1];  
        if(c=='.') dec=i;  
        else if(!dec) res = res*10 + c-'0';  
        else res += (c-'0')/tentimes(i-dec);  
    }  
    return res;  
}  
  
double calculate(string s){  
    double res, t;  
    stack<double> num;  
    string temp;  
    int i;  
    for(i=0;i<s.size();i++){  
        temp="";  
        if(isdigit(s[i]) || s[i]=='.'){  
            while(isdigit(s[i]) || s[i]=='.') temp+=s[i++]; //如果最后一位是数字，这样做会出错   
            num.push(str2double(temp));  
        }  
        else{  
            switch (s[i]){  
                case '+': t=num.top(); num.pop(); t+=num.top();num.pop();num.push(t);break;  
                case '-': t=num.top(); num.pop(); t=num.top()-t;num.pop();num.push(t);break;  
                case '*': t=num.top(); num.pop(); t*=num.top();num.pop();num.push(t);break;  
                case '/': t=num.top(); num.pop(); t=num.top()/t;num.pop();num.push(t);break;  
                default: cerr << "Fatal Error! Result would be wrong!" << endl; system("pause");break;  
            }  
        }  
    }  
    res=num.top();  
    return res;  
}  
  
  
int main(){  
    string mid, sur;  
      
    cin >> mid;  
    sur = shorten(mid);  
    cout << "successfully executed! The right hand operator expression is: " << endl;  
    cout << sur << endl;  
    cout << "The result is: " <<calculate(sur) << endl;  
  
    system("pause");  
    return 0;  
}  
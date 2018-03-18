#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int h[111111] = {0};
int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    //transform(a.begin(),a.end(),a.begin(),::tolower);
    //transform(b.begin(),b.end(),b.begin(),::toupper);upper
    //cout<<a;
    bool flag = 0;
    int cnt = 0;
    for(int i = 0;i<a.size();i++){
        if(a[i]=='+')flag = 1;}
        if(flag){
        for(int i = 0;i<b.size();i++){
        if(b[i]>='A' &&b[i]<='Z')b[i]='#';}}
        transform(a.begin(),a.end(),a.begin(),::toupper);
    
        for(int i = 0;i<a.size();i++){
        for(int j = 0;j<b.size();j++){
        
        if(b[j]==a[i])b[j]='#';
        }

    }
    transform(a.begin(),a.end(),a.begin(),::tolower);
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<b.size();j++){
        
        if(b[j]==a[i])b[j]='#';
        }

    }
    for(int i = 0;i<b.size();i++){
        if(b[i]!='#'){cout<<b[i];}

    }
    cout<<'\n';
}
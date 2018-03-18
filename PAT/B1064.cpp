#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int h[11111] ;
int p[11111] ={0};
int findr(int a){
    if(a == h[a])return a;
    else{int tmp = findr(h[a]);
         h[a] = tmp;
         return tmp;}
}

void Union(int a1,int b1){
a1 = findr(a1);
b1 = findr(b1);
if(a1!=b1) h[a1] = b1;}

int zz(int a){
    int r = 0;
    while(a){
    int t = a%10;
    r = r+t;
    a =a /10;
    }
    return r;
}
int main(){
    vector<int> o;
    int a,b;
    cin>>a;
    while(a--){
    cin>>b;p[zz(b)]++;}
    //transform(a.begin(),a.end(),a.begin(),::tolower);
    //transform(b.begin(),b.end(),b.begin(),::toupper);upper
    //cout<<a;
    int cnt = 0;
    for(int i = 0;i<11111;i++){
        if(p[i]!=0){cnt++;o.push_back(i);}
    }
    cout<<cnt<<'\n';
    for(vector<int>::iterator it = o.begin();it<o.end()-1;++it ){
        cout<<*it<<' ';

    }
    
    cout<<o[o.size()-1];
}
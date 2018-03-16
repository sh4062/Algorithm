#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct s{
    char id[20];
    char s;
    char c[20];
    int sc;
}a,b,res1,res2;


int main(){
    int n;
    cin>>n;
    bool f1 = 0;
    bool f2 = 0;
    res1.sc = 0;
    res2.sc = 100;
    //cout<<b.ss;
    while(n--){
    scanf("%s %s %s %d",a.id,&a.s,a.c,&a.sc);
    if(a.s == 'M'&&f2 == 0) {f2 =1;res2 = a;}
    if(a.s == 'F'&&f1== 0) {f1 = 1;res1 = a;}
    if(a.s == 'F' &&a.sc >= res1.sc) res1 = a;
    if(a.s == 'M' &&a.sc <= res2.sc) res2 = a;

     

    }
    //cout<<f2;
    if(f1)
    {cout<<res1.id<<" "<<res1.c<<'\n';}
    else {cout<<"Absent"<<'\n';}
    if(f2)
    {cout<<res2.id<<" "<<res2.c<<'\n';}
    else {cout<<"Absent"<<'\n';}
    if(f1&&f2){cout<<res1.sc-res2.sc<<'\n';}
    else {cout<<"NA"<<'\n';}

}
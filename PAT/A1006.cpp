#include<iostream>
#include<cstdio>
using namespace std;
struct s{
    char id[20];
    int h,m,s;
    int hh,mm,ss;
}a,b,res1,res2;

bool cmp1(s a,s b){
    if(a.h != b.h) return a.h <b.h;
    else if(a.m != b.m ) return   a.m < b.m;
    else if(a.s!=b.s) return a.s<b.s;
   
}
bool cmp2(s a,s b){
    if(a.hh != b.hh) return a.hh >b.hh;
    else if(a.mm != b.mm ) return   a.mm > b.mm;
    else if(a.ss!=b.ss) return a.ss>b.ss;
   
}
int main(){
    int n;
    cin>>n;
    scanf("%s %02d:%02d:%02d %02d:%02d:%02d",a.id,&a.h,&a.m,&a.s,&a.hh,&a.mm,&a.ss);
    //cout<<b.ss;
    n = n-1;
    res1 = a;res2 = a;
    while(n--){
    scanf("%s %02d:%02d:%02d %02d:%02d:%02d",a.id,&a.h,&a.m,&a.s,&a.hh,&a.mm,&a.ss);
    if(cmp1(a,res1))(res1 = a);
     if(cmp2(a,res2))(res2 = a);


    }
    cout<<res1.id<<" "<<res2.id<<'\n';

}
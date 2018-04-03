#include<iostream>  
#include<string.h>
#include<cstdio>
#include<algorithm>  
#include<set>  
using namespace std;
const int N =51;
set<int> st[N];

void cmp(int x,int y){
    int total = st[y].size(),same = 0;
    for(set<int>::iterator it = st[x].begin();it != st[x].end();it++){
        if(st[y].find(*it)!=st[y].end())same++;
        else total++;
    }
    printf("%.1f%%\n",same*100.0/total);
}

int main(){
    int n,k,v,q,r1,r2;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>k;
        for(int j = 0;j<k;j++){
            cin>>v;
            st[i].insert(v);}}

    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>r1>>r2;
        cmp(r1,r2);}
}
#include<iostream>
#include<cstdio>
using namespace std;
struct person{
    char name[10];
    int y,m,d;
}old,young,l,r,t;

bool lt(person a,person b){
    if(a.y != b.y)return a.y <= b.y;
    else if(a.m != b.m) return a.m <= b.m;
    else return a.d <= b.d;
}

bool gt(person a,person b){
    if(a.y != b.y)return a.y >= b.y;
    else if(a.m != b.m) return a.m >= b.m;
    else return a.d >= b.d;
}

void init(){
    young.y = l.y = 1814;
    old.y = r.y = 2014;
    young.m = old.m = l.m = r.m =9;
    young.d = old.d = l.d = r.d =6;
}

int main(){
    init();
    int n, num = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf("%s %d/%d/%d",t.name,&t.y,&t.m,&t.d);
        if(lt(t,r)&&gt(t,l)){
            num++;
            if(lt(t,old)) old = t;
            if(gt(t,young)) young = t;
        }

    }
    if(num == 0) cout<<"0"<<endl;
    //else if(num == 1) cout<<num<<" "<<old.name<<endl;
    else printf("%d %s %s\n",num,old.name,young.name);
}
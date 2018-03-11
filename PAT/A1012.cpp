#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 2010;
struct f{
    int id;
    int c;
    int m;  
    int e;
    int a;
    int rank[4] ;
};
bool cmpc(f x,f y){//>= will cause seg-erroe.
    return x.c > y.c;
}
bool cmpm(f x,f y){
    return x.m > y.m;
}
bool cmpe(f x,f y){
    return x.e > y.e;
}
bool cmpa(f x,f y){
    return x.a > y.a;
}
string mp[5] = {"N/A","A","C","M","E"};
int main(){
    ios::sync_with_stdio(false);
    int n,q,tmp,r1,r2;
    cin>>n>>q;
    f stu[2020];

    for(int i = 0;i < n;i++){
        cin>>stu[i].id>>stu[i].c>>stu[i].m>>stu[i].e;
        stu[i].a = (stu[i].c+stu[i].m+stu[i].e)/3;

    }
    sort(stu,stu+n,cmpa);
    for(int i = 0;i < n;i++){
        stu[i].rank[0] = 0;
        stu[i].rank[0] = stu[i].rank[0]+i+1;
        if(i >= 1&& stu[i].a == stu[i-1].a) {stu[i].rank[0] = stu[i-1].rank[0];}
    }
     sort(stu,stu+n,cmpc);
    for(int i = 0;i < n;i++){
        stu[i].rank[1] = 0;
        stu[i].rank[1] = stu[i].rank[1]+i+1;
        //cout<<stu[i].id<<stu[i].rank[0];
        if(i >= 1&& stu[i].c == stu[i-1].c) {stu[i].rank[1] = stu[i-1].rank[1];}
    }
     sort(stu,stu+n,cmpm);
    for(int i = 0;i < n;i++){

        stu[i].rank[2] = stu[i].rank[2]+i+1;
        if(i >= 1&& stu[i].m == stu[i-1].m) {stu[i].rank[2] = stu[i-1].rank[2];}
    }
     sort(stu,stu+n,cmpe);
    for(int i = 0;i < n;i++){
        stu[i].rank[3] = stu[i].rank[3]+i+1;
        //cout<<stu[i].rank[2];
        if(i >= 1&& stu[i].e == stu[i-1].e) {stu[i].rank[3] = stu[i-1].rank[3];}
       //cout<<stu[i].rank[2];
    }
   
    
    for(int t = 0;t < q;t++){
        cin>>tmp;

        for(int j = 0;j < n;j++){
        if(tmp == stu[j].id){
            r1 =*min_element(stu[j].rank,stu[j].rank+4);
            for(int i = 0;i<4;i++){
                
                if(stu[j].rank[i]==r1){r2 = i;break;}

            }
            
        cout<<r1<<" "<<mp[r2+1]<<'\n';break; }
        else if(tmp != stu[j].id && j == n-1) cout<<mp[0]<<'\n';
        
    }

}
}
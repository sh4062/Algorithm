#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 10005;
struct dc{
    int id;
    int d;
    int c;
};
bool compare(dc a,dc b){
    if(a.d + a.c != b.c+b.d) return (a.d + a.c)>(b.c+b.d);
    else if(a.d!=b.d) return (a.d > b.d);
    else return a.id < b.id;
}
int main(){
    ios::sync_with_stdio(false);  
    dc stu;
    vector<dc> r1,r2,r3,r4;
    int n,l,h,count = 0;
    cin>>n>>l>>h;
    for(int i = 0;i < n;i++){
        cin>>stu.id>>stu.d>>stu.c;
        if(stu.d>=l&&stu.c>=l){
            count++;
            if(stu.d>=h&&stu.c>=h){
                r1.push_back(stu);}
               else if(stu.d>=h)         
                 r2.push_back(stu);
             else  if(stu.d>=stu.c)     
                 r3.push_back(stu);
             else
                 r4.push_back(stu);     
            }

        }
    sort(r1.begin(),r1.end(),compare);
    sort(r2.begin(),r2.end(),compare);
    sort(r3.begin(),r3.end(),compare);
    sort(r4.begin(),r4.end(),compare);

    cout<<count<<endl;
    for(int i=0; i<r1.size(); i++)
   {
           cout<<r1[i].id<<" "<<r1[i].d<<" "<<r1[i].c<< '\n';
           //printf("%d %d %d\n",r1[i].id,r1[i].d,r1[i].c);
   }
   for(int i=0; i<r2.size(); i++)
   {
           cout<<r2[i].id<<" "<<r2[i].d<<" "<<r2[i].c<< '\n';
           //printf("%d %d %d\n",r2[i].id,r2[i].d,r2[i].c);
   }
   for(int i=0; i<r3.size(); i++)
   {
           cout<<r3[i].id<<" "<<r3[i].d<<" "<<r3[i].c<< '\n';
           //printf("%d %d %d\n",r3[i].id,r3[i].d,r3[i].c);
   }
   for(int i=0; i<r4.size(); i++)
   {
           cout<<r4[i].id<<" "<<r4[i].d<<" "<<r4[i].c<< '\n';
           //printf("%d %d %d\n",r4[i].id,r4[i].d,r4[i].c);
   }


}
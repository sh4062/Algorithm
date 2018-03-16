#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct stu
{
    string name;
    int online_score,mid_term,final_term,final_score;
    stu()
    {
        mid_term = final_term = final_score = -1;
    }
}s[30001];
bool cmp(stu a,stu b)
{
    if(a.final_score == b.final_score)return a.name < b.name;
    return a.final_score > b.final_score;
}
int main()
{
    int p,m,n,no = 0;
    string name;
    int score;
    map<string,int> q;
    cin>>p>>m>>n;
    for(int i = 0;i < p;i ++)
    {
        cin>>name>>score;
        if(score >= 200 && score <= 900)
        {
            if(!q[name])q[name] = ++ no,s[no].name = name;
            s[q[name]].online_score = score;
        }
    }
    for(int i = 0;i < m;i ++)
    {
        cin>>name>>score;
        if(q[name] && score >= 0 && score <= 100)
        {
            s[q[name]].mid_term = score;
        }
    }
    for(int i = 0;i < n;i ++)
    {
        cin>>name>>score;
        if(q[name] && score >= 0 && score <= 100)
        {
            s[q[name]].final_term = score;
            if(s[q[name]].mid_term <= s[q[name]].final_term)s[q[name]].final_score = s[q[name]].final_term;
            else s[q[name]].final_score = (int)(s[q[name]].final_term * 0.6 + s[q[name]].mid_term * 0.4 + 0.5);
        }
    }
    sort(s+1,s+no+1,cmp);
    for(int i = 1;i <= no;i ++)
    {
        if(s[i].final_score < 60)break;
        cout<<s[i].name<<' '<<s[i].online_score<<' '<<s[i].mid_term<<' '<<s[i].final_term<<' '<<s[i].final_score<<endl;
    }
}
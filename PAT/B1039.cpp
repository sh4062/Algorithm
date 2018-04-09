#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int a[1001]= {0},b[1001]= {0};
    int len;
    for(int i=0; i<s2.size(); i++)
        a[s2[i]-'0']++;
    for(int i=0; i<s1.size(); i++)
        b[s1[i]-'0']++;
    len=s2.size();
    for(int i=0; i<123; i++)
    {
        if(a[i]>b[i])
        {
            len=len-(a[i]-b[i]);
        }

    }
    int n=s2.size()-len;
    if(n)
        cout<<"No "<<n<<endl;
    else
        cout<<"Yes "<<s1.size()-s2.size()<<endl;
    return 0;

}
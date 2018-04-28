//1024. Palindromic Number (25)
#include<bits/stdc++.h>
using namespace std;

string add(string x,string y){
    int a[100]={0},b[100]={0},c[100]={0};
     string r;
     int i;
     for (i = 0; i < x.size(); i++) //从尾部开始加111+999=1110
            a[i] = x[x.size() - i - 1] - '0';
        for (i = 0; i < y.size(); i++)
            b[i] = y[y.size() - i - 1] - '0';
     int flag = 0,sum=0;
     int k = max(x.size(), y.size());
        for (i = 0; i <= k; i++)//进位
        {
            c[i] += a[i] + b[i];
            if (c[i] > 9)
            {
                c[i + 1]++;
                c[i] %= 10;
            }
        }
        while (c[i] == 0)
            i--;
        for(i;i>=0;i--){
            r = r+to_string(c[i]);
        }

     return r;
}

int main(){
    string a;
    cin>>a;
    int n;
    cin>>n;
    unsigned long long i =0;
    string  t1 = a;
    string  t2 = a;
    // reverse(t2.begin(),t2.end());
    // t2=add(t1,t2);
    for(i;i<n;i++){
        t1 = t2;
        reverse(t2.begin(),t2.end());
        
        if(t1==t2)break;
        else{t2=add(t1,t2);}
        
    }
    cout<<t2<<'\n';
    cout<<i;
    
}
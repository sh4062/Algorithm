
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
long long int m[100005];

int main() {
    long long  int n,  a, b, num, temp;
    long long  int p;
    cin>>n>>p;
    for(int i =0;i<n;i++){
        cin>>m[i];

    }
    sort(m,m+n);
    //if(m[0]*p>=m[n-1])cout<<n;
    int t1 = 0,t2 = n-1,maxn = 0;

for(long int i = 0;i<n;i++){
for(long int j = i+maxn;j<n;j++){
if(m[j]>m[i]*p)
break;
maxn++;
}}
    cout<<maxn;
    
}
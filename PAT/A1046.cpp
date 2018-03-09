#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 100005;
int dis[MAX], A[MAX];
int main() {
    int sum = 0,query,n,l,r;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>A[i];
        sum += A[i];
        dis[i] = sum;}
    cin>>query;
    for(int i = 1 ;i <= query; i++){
        cin>>l>>r;
        if(l > r) swap(l, r);
        int tmp = dis[r-1] - dis[l-1];
        cout<<min(tmp,sum-tmp)<<endl;
    }
}

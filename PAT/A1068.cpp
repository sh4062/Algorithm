#include<iostream>
#include<algorithm>
using namespace std;
int w[10010]={0};
int dp[10001][101];
int coin[10010];
bool cmp(int a,int b){
    return a>b;
}

int main(){
    int n,m;
    cin>>n>>m;
    int t;
    for(int i = 1 ;i<=n;i++){
        cin>>coin[i];

    }
    sort(coin+1,coin+1+n,cmp);
    for (int i = 1; i <= n; i++){
        for (int v = 0; v <= m; v++){
            
        }
    }



}
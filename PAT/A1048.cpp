#include<iostream>
#include<algorithm>
using namespace std;
int hashn[1005];
int main(){
    int n,m,t;
    cin>>n>>m;
    while(n--){
        cin>>t;
        hashn[t]++;
    }
    for(int i = 1;i<m;i++){
        if(hashn[i] &&hashn[m-i]){
            if(i==m-i&&hashn[i]<=1){continue;}
            cout<<i<<" "<<m-i<<'\n';
            return 0;
        }

    }
    cout<<"No Solution";
    return 0;

}
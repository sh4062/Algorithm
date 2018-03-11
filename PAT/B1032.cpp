#include<iostream>
using namespace std;
const int maxn = 100005;
int main(){
    int res[maxn] = {0},r1 = 0,r2 = 0,n,i,j;
    cin>>n;
    while(n--){
        cin>>i>>j;
        res[i] += j;
        if(res[i]>r2){r1 = i; r2=res[i];}
    }
    cout<<r1<<" "<<r2;

}
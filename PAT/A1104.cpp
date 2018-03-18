#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n;
    double t ,res = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>t;
        res = res+ t*i*(n+1-i);
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<res;
}

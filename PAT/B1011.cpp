#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int t =1;
    while(n--){
    long long a,b,c;
    cin>>a>>b>>c;
    if(a+b>c) {cout<<"Case #"<<t<<": true"<<endl;t++;}
    else{cout<<"Case #"<<t<<": false"<<endl;t++;}
    }
}
#include <iostream>
using namespace std;
int main() {
    int N;
    char c;
    cin >> N >> c;
    int a = 0;
    int res =0;
    for(int i = 3;i<N;i = i + 2){
        
        a = a+i;
        if(2*a+1>N){
            a = i-2;
            //cout<<a;
            break;
        } 
        else if(2*a+1==N){
            a = i;
            //cout<<a;
            break;
        } 
    }
    
    int i = 0;
    for(i = a;i>=3;i = i - 2){
        if(a!=i){for(int k = a-i;k>0;k=k-2){cout<<" ";}}
        for(int j = i;j>1;j--){
            
            cout<<c;

        }cout<<c<<endl;


    }
    if(a!=i){for(int k = a-i;k>0;k=k-2){cout<<" ";}}
    cout<<c<<endl;
    for(i = 3;i<=a;i = i + 2){
        if(a!=i){for(int k = a-i;k>0;k=k-2){cout<<" ";}}
        for(int j = i;j>1;j--){
            
            cout<<c;

        }cout<<c<<endl;
        
    
    }
    res = 0;
    for(int m = 3;m<=a;m = m + 2){
        res = res + m;}
    cout<<N-2*res-1<<endl;
    
}
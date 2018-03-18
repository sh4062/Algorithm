#include<iostream>
using namespace std;
int a[101];
int main(){
    int c;
    cin>>c;
    int i;
    while(c--){
        cin>>i;
        a[i]++;
    }
    int q;
    cin>>q;
    while(q--){
        cin>>i;
        if(q>0){
        cout<<a[i]<<" ";}
        else   cout<<a[i];
    }

}
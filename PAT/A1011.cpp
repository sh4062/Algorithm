#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    char s[3] = {'W','T','L'};
    double a[3][3];
    double res = 1,max[3]={0},maxi[3]={0};
    for(int i = 0;i<3;i++){
    cin>>a[i][0]>>a[i][1]>>a[i][2];
    for(int j = 0;j<3;j++){
        if(max[i]<a[i][j]){max[i] = a[i][j];maxi[i] = j;}
        
    }}
    for(int j = 0;j<3;j++){
        cout<<s[int(maxi[j])]<<" ";
    }
    for(int j = 0;j<3;j++){
        res = res * max[j];
    }
    res =( res*0.65-1) *2;
    res=round(res*1000)/1000;
    printf("%.2f", res);
    return 0;
    
        
    
}
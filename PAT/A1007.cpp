#include<iostream>  
#include<string.h>
#include<cstdio>
#include<algorithm>  
using namespace std;
int t[10005];
int main(){
    
        int n;
        cin>>n;
        for(int i = 0;i<n;i++){
            cin>>t[i];
        }
        int s=0,maxs = 0,maxi=0,maxl=0;
        for(int i = 0;i<n;i++){
            s = s + t[i];
            if(maxs!=max(s,maxs)){
            maxs=max(s,maxs);maxi = i;}
            
            
            if(s<0){s=0;}
        }int tmp = maxs;
        for(int i = maxi;i>=0;i--){
            
            tmp = tmp-t[i];
            maxl++;
            if(tmp==0) break;


            
        }
        if(maxs<0){cout<<0<<" "<<t[0]<<" "<<t[n];return 0;}

        cout<<maxs<<" "<<t[maxi-maxl+1]<<" "<<t[maxi];

    return 0;
}
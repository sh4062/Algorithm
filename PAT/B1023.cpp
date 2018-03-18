#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int t[10]={0};
int main(){
    int a;
        int i =0;
        for( i = 0; i < 10; i++ ) {
            cin>>t[i];
            

        }
        int max0 = 0;

        if(t[0]==0){
            
            for(int z =0;z<10;z++){
            if(t[z]!=0){
                for(int x = t[z];x>0;x--) cout<<z;
            }
           
        }}
        else{
         for(int m = 1;m<10;m++){if(t[m]!=0){max0 = m;break;}}
         cout<<max0;
         t[max0]--;
         for(int z =0;z<10;z++){
            if(t[z]!=0){
                for(int x = t[z];x>0;x--) cout<<z;
            }
           
        }

        }
        cout<<'\n';
        // 



}

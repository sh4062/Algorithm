#include<iostream>
#include<algorithm>
using namespace std;
int hashn[15];
int hashn2[111]={0};
int main(){
    int n,m = 0,t;
    cin>>n;
    while(n--){
        cin>>t;
        hashn[t]++;
    }
    for(int i = 1;i<11;i++){
        if(hashn[i]>0){
            for(int j = i+1;j<11;j++){
            if(hashn[j]>0 && hashn2[10*i+j]==0&&hashn2[10*j+i]==0) {m = m+10*i+j+10*j+i; }}}
            
      

    }
    cout<<m;
    return 0;

}
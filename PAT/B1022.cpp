#include<iostream>  
using namespace std;  
  
void test(int m,int k){  
    if(m/k==0)cout<<m;  
    else{   
       test(m/k,k);  
       cout<<m%k;}  
   }  
int main(){  
    int A,B,D;  
    cin>>A>>B>>D;  
    int cnt=0;  
    cnt=A+B;  
    test(cnt,D); 
      
    return 0;  
    }  
#include<iostream>
#include <algorithm>   
#include <stdio.h>
using namespace std;
string int_to_string(int i)  
{  
    char ch[10];  
    sprintf(ch, "%d", i);  
    string s(ch);  
  
    return s;  
}  
int main(){
  int n = 0,m = 0,sub = 0;
  cin>>n;
  int r1 = 0, r2 = 0, r3 = 0;
  r1 = n % 10;
  n = n/10;
  r2 = n % 10;
  n = n/10;
  r3 = n;
  string s;
  for(int i = 1;i <= r3;i++){s = s + "B";}
  for(int i = 1;i <= r2;i++){s = s + "S";}
  for(int i = 1;i <= r1;i++){s = s + int_to_string(i);}
 
 


  cout<<s;
    return 0;  
    
  
}
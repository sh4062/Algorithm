#include <iostream>  
#include <algorithm>  
#include<string>
#include<sstream>
#include<cstdio>
using namespace std;  
int mp[26]={0};
string its(int a){
    stringstream ss;
    ss<<a;
    return ss.str();
}
int main()  

{  
   string a;
   getline(cin,a);
   transform(a.begin(), a.end(), a.begin(), ::tolower);
   for(int i = 0;i<a.size();i++){
       mp[int(a[i])-97]++;
   }
   int max = mp[0];
   int maxi = 0;
   for(int i = 1;i<26;i++){
       if(mp[i]>max) {max=mp[i];maxi = i;}}

   printf("%c %d\n", maxi+97,max ) ;
   }  
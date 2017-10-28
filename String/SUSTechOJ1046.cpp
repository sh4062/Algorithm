#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int T,n,x,y;
    string s;
    string o;
    cin >> T;
    while(T--){
        cin >>s>>n;
    while(n--){
        cin >>o;
         
     if(o=="Sstr"){ 
        cin>> x>>y;
        cout<<s.substr(x,y-x+1)<<endl; }
         
     if(o== "Add"){
     string a;
     int ad;
     cin >>a>>ad;
     s=s.insert(ad, a);
     
      cout << s << endl;  }
      
      if(o== "Delete"){
      int e=0;
      cin>>e;
      s=s.erase(e,1);
      cout <<s << endl;  }
      if(o== "Reverse"){
      x=0;y=0;
      cin>> x>>y;
      reverse(s.begin()+x, s.end()-(s.size()-y-1));
      
      cout<<s<<endl;}
      }}
	}




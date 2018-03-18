#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int h[128] = {0};
int main(){
    string a,b;
    cin>>a>>b;
    transform(a.begin(),a.end(),a.begin(),::toupper);
    transform(b.begin(),b.end(),b.begin(),::toupper);
    for(int i = 0;i<a.size();i++){
        if(a[i]!=b[i]&&h[int(a[i])]==0){h[int(a[i])]++;cout<<a[i];b.insert(0,1,'#');}
        else if(a[i]!=b[i]&&h[int(a[i])]!=0){b.insert(i,1,'#');}
        

    }
}
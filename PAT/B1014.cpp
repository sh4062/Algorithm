#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    //if(a.length() > b.length()) swap(a,b);
    int i = 0,r1 = 0,r2 = 0,r3 = 0;
    for(i;i < a.length();i++){
            if(a[i] == b[i] && (a[i]>='A'&&a[i]<='G')){
                break;
            }
    }
    r1 = int(a[i]) - 64;
    i++;
    string re[8] = {" ","MON","TUE","WED","THU","FRI","SAT","SUN"};
    for(i;i < a.length();i++){
            if(a[i] == b[i] &&(a[i]>='0'&&a[i]<='9')){
                r2 = int(a[i]) - 48;
                break;
            } else if(a[i] == b[i] &&(a[i]>='A'&&a[i]<='N')){ r2 = int(a[i]) - 65 + 10;break;}
    }
    i = 0;
    for(i = 0;i < c.length();i++){
            if(c[i] == d[i] &&((c[i]>='A'&&d[i]<='Z')||(c[i]>='a'&&d[i]<='z'))){
                break;
            }
    }
    r3 = i;
    cout<<re[r1];
 

    printf(" %02d:%02d",r2,r3);
}
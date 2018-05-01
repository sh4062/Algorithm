//1027. Colors in Mars (20)
#include <bits/stdc++.h>
using namespace std;
string t16(int a){
    int b = a/13;
    int c =a%13;
    string res;
    if(c<10) res = res+to_string(c);
    else if(c==10)res = res+"A";
    else if(c==11)res = res+"B";
    else if(c==12)res = res+"C";
    if(b<10) res = to_string(b)+res;
    else if(b==10)res = "A"+res;
    else if(b==11)res = "B"+res;
    else if(b==12)res = "C"+res;
    return res;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    string res;
    string aa,bb,cc;
    aa = t16(a);
    bb = t16(b);
    cc = t16(c);
    cout<<'#'<<aa<<bb<<cc;
}
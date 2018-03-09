#include<iostream>
using namespace std;
int main(){
    int T,tcase = 1;
    cin>>T;
    while(T--){
        long long a,b,c;
        cin>>a>>b>>c;
        long long res = a + b;
        bool flag;
        if(a > 0 && b > 0 && res < 0) flag = true;
        else if(a < 0 && b < 0 && res >= 0) flag = false;
        else if(res >  c)flag = true;
        else flag = false;
        if(flag == true) {
        cout<<"Case #"<<tcase<<": true"<<endl;
        tcase++;
        } else{
            cout<<"Case #"<<tcase<<": false"<<endl;tcase++;

        }
    }
    }
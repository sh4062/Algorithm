#include <iostream>
#include <cstdio>
#include <sstream>
#include <string.h>
using namespace std;
double sti( string a){
    stringstream t(a);
    double b;
    t >>b;
    return b;
}
int main() {
    int n, cnt = 0;
    string a;
    double temp, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin>>a;
        int flag = 1;
        int point = 0;
        int point_s = 0;
        if(int(a[0])>58||int(a[0])<47) flag = 0;
        if(int(a[0])==45)flag = 1;
        //cout<<flag;
        for(int j = 1; j < a.size(); j++) {
            if(int(a[j])<46||int(a[j])>57){flag = 0;}
            if(int(a[j])==46 ){point++;point_s=j;}
            
        }
        if(point>=2)flag = 0;
        if(point == 1&&a.size()-1-point_s>2)flag = 0;
        

        if(flag == 0 || sti(a) < -1000 || sti(a) > 1000) {
            cout<<"ERROR: "<<a<<" is not a legal number"<<'\n';
            continue;
        } else {
            sum += sti(a);
            //cout<<sti(a);
            cnt++;
        }
    }
    if(cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(cnt > 1) {
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}
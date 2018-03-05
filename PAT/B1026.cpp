#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    int c1,c2;
    cin>>c1>>c2;
    int ans = c2 - c1;
    if(ans%100 >= 50) {
        ans = ans / 100 + 1;
    } else {
        ans = ans / 100;
    }
    cout<<setfill('0')<<setw(2)<< ans/3600<<":"<<setfill('0')<<setw(2)<<ans%3600/60<<":"<<setfill('0')<<setw(2)<<ans%60;
}
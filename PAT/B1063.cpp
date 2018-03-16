#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n,count = 0;
    cin>>n;
    double r[10005];
    double c[10005];
    double m = 0,res;
    while(n--){
        cin>>r[count]>>c[count];
        count++;
    }
    for(int i = 0;i < count;i++){
        if(m < sqrt(r[i]*r[i]+c[i]*c[i])) m = sqrt(r[i]*r[i]+c[i]*c[i]);

    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<m;
}
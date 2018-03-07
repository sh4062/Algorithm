#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int count[5] = {0};
    int ans[5] = {0};
    int n, tmp;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>tmp;
        if(tmp % 5 == 0){
            if(tmp % 2 ==0){
            ans[0] += tmp;
            count[0]++;}
        } else if(tmp % 5 == 1){
            if(count[1] % 2 == 0){
                ans[1] += tmp;
            } else {ans[1] -= tmp;}
            count[1]++;
        } else if (tmp % 5 == 2){
            count[2]++;
        } else if (tmp % 5 == 3){
            ans[3] += tmp;
            count[3]++;
        } else {
            if(tmp > ans[4]){
                ans[4] = tmp;
            }
            count[4]++;
        }
    }
    if(count[0] == 0){cout<<"N ";}
    else cout<<ans[0]<<" ";
    if(count[1] == 0){cout<<"N ";}
    else cout<<ans[1]<<" ";
    if(count[2] == 0){cout<<"N ";}
    else cout<<count[2]<<" ";
    if(count[3] == 0){cout<<"N ";}
    else cout<<setiosflags(ios::fixed)<< setprecision( 1 )<<double(ans[3])/count[3]<<" ";
    if(count[4] == 0){cout<<"N";}
    else cout<<ans[4];

}
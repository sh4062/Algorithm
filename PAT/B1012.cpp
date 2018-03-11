#include<iostream>
using namespace std;
int main()
{
    int count[5] = {0};
    int ans[5] = {0};
    int n,tmp;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>tmp;
        if(tmp % 5 == 0){
            if(tmp % 2 ==0){
                ans[0] += tmp;
                count[0]++;
            }
        }else if(tmp%5==1){

        }
    }
}
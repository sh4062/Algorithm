#include<iostream>
using namespace std;
const int I = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'};
int s[I+1], e[I+1], ne[I+1];
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= I; i++){
        s[i]=i;
    }
    for(int i = 1;i <= I; i++){
        cin>>ne[i];
    }  
    for(int step = 0; step < n; step++)
    {
        for(int step =1;step <=I; step ++){
            e[ne[step]] = s[step];// Card step's index is saved in ne[i]
        }
        for(int i = 1;i <= I;i++){
            s[i] = e[i];
        }

    }
    for(int i =1; i <= I;i++){
        if(i != 1) cout<<(" ");
        s[i]--;
        cout<<mp[s[i] / 13]<<s[i]%13+1;
        
    }
}

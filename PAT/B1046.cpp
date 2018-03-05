#include<iostream>
using namespace std;
int main() {
    int n,fa = 0,fb = 0;
    cin>>n;
    while(n--){
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        if(a1 + b1 == a2 && a1 + b1 !=b2) {
            fb++;
        }
        else if(a1 + b1 != a2 && a1 + b1 ==b2) {
            fa++;
        }
    }
    cout<<fa<<" "<<fb;
}

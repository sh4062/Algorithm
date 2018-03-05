#include<iostream>
using namespace std;

int main() {
    long long a,b,a1,b1;
    cin>>a>>a1>>b>>b1;
    long long pa = 0,pb = 0;
    while(a != 0) {
        if(a%10 == a1) pa = pa*10 + a1;
        a = a/10;
    }
    while(b != 0) {
        if(b%10 == b1) pb = pb*10 + b1;
        b = b/10;
    }
    cout<< pa+pb;

}
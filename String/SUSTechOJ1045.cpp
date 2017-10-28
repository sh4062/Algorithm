#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main(){
    int a;
    string b;
    
    cin >> a;
    while(a--){
    cin>>b;
        cout << b.size()*(1+b.size())/2 << endl;}
	return 0;
}

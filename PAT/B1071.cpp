#include<iostream>  
using namespace std;  
int main() {  
    int t1, k1, n1, b, t, n2, i, total=0;  
    cin>>t1>>k1;  
    total = t1;  
    for (i=0; i<k1; i++) {  
        cin>>n1>>b>>t>>n2;  
        if (t > total)  
            cout<<"Not enough tokens.  Total = "<<total<<"."<<endl;  
        else if ((n1 > n2 && b == 0) || (n1 < n2 && b == 1)) {  
            total += t;  
            cout<<"Win "<<t<<"!  Total = "<<total<<"."<<endl;  
        }  
        else if ((n1 > n2 && b == 1) || (n1 < n2 && b == 0)) {  
            total -= t;  
            cout<<"Lose "<<t<<".  Total = "<<total<<"."<<endl;  
        }  
        if (total == 0) {  
            cout<<"Game Over.";  
            break;  
        }  
    }  
    return 0;  
}  
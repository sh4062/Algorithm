#include <iostream>  
#include <string>  
using namespace std;  
  
string a;  
  
void deal1(){  
    getline(cin, a);  
    for(int i = 0; i < a.length(); i++)  
    {  
        int count = 0;  
        while(a[i] == a[i+1])  
            i++, count++;  
        if(count != 0)    
            cout << count+1;  
        cout << a[i];  
    }     
}  
void deal2(){  
    getline(cin, a);  
    for(int i = 0; i < a.length(); i++)  
    {  
        int sum = 0;  
        while(a[i] <= '9' && a[i] >= '0')  
            sum = sum*10 + a[i++]-'0';//数个数(两位以上的数字)   
        for(int j = 0; j < sum; j++)  
            cout << a[i];  
        if(sum == 0)  
            cout << a[i];  
    }  
}  
int main(){  
    char ch;  
    cin >> ch;  
      
    getchar();//吞回车   
      
    if(ch == 'C')  
        deal1();  
    else if(ch == 'D')  
        deal2();  
    cout << endl;  
    return 0;  
}   
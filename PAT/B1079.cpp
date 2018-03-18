#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string splus(string s, string t) {
    int carry = 0;
    string result;
    for (int i = 0; i < s.length(); i++) {
        result += (s[i] + t[i] - '0' - '0' + carry) % 10 + '0';
        carry = (s[i] + t[i] - '0' - '0' + carry) / 10;
    }
    if (carry != 0) result += carry + '0';
    reverse(result.begin(), result.end());
    return result;
}

bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

int main(){
    string a,b,c;
    cin>>a;
    if(isPalindrome(a)){
            cout<<a<<" is a palindromic number."<<'\n';return 0;}
    b = a;
    reverse(a.begin(),a.end());
    
    for(int i = 0;i<10;i++){
        c = splus(a,b);
        cout<<b<<" + "<<a<<" = "<<c<<'\n';
        if(isPalindrome(c)){
            cout<<c<<" is a palindromic number."<<'\n';return 0;}
        a = c;    
        b = a;
        reverse(a.begin(),a.end());
    }
    
    cout<<"Not found in 10 iterations.";
}
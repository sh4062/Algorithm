#include <iostream>  
#include <queue>  
#include <algorithm>  
#include <functional>  
#include <string>  
using namespace std;  
int main() {  
    string s;  
    while (getline(cin, s)) {  
        int ret=0;  
        int n = s.size();  
        sort(s.begin(), s.end());  
        int cnt = 0;  
        priority_queue<int, vector<int>, greater<int> > heap;  
        for (int i = 0, j; i < n;) {  
            j = i;  
            while (j < n && s[j] == s[i]) ++j;  
            heap.push(j - i);  
            i = j;  
            ++cnt;  
        }  
        for (int i = 0; i < cnt-1; i++) {  
            int a = heap.top();  
            heap.pop();  
            int b = heap.top();  
            heap.pop();  
            heap.push(a+b);  
            ret += a + b;  
              
  
        }  
        cout << ret << endl;  
  
    }  
    return 0;  
}  

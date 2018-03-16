
#include <iostream>  
#include <string>  
#include <vector>  
#include <algorithm>  
using namespace std;  
int main(){
    int n;
    cin>>n;
    string s, res;
    vector <string> t;
    while(n--){
        cin>>s;
         reverse(s.begin(), s.end());  
         t.push_back(s);
    }
    string s1 = t[0];  
    for (int i = 0; i < s1.size(); i++){  
        bool flag = true;  
       for (int j = 1; j < t.size(); j++){  
           if (t[j][i] != s1[i]){  
                flag = false;  
                break;  
            }  
            if (flag)  
                res = res+ s1[i];  
            else  
                break;  
        }  }

        if (res.empty())  
        cout << "nai" << endl;  
    else{  
        reverse(res.begin(), res.end());  
        cout << res << '\n';  
    }  
    return 0;  
}
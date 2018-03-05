#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    string n;
    int res = 0;
    map<int, string> r; 
    string re; 
    r.insert(map<int, string>::value_type (0, "ling"));  
    r.insert(map<int, string>::value_type (1, "yi"));  
  
    r.insert(map<int, string>::value_type (2, "er"));  
  
    r.insert(map<int, string>::value_type (3, "san"));  
    r.insert(map<int, string>::value_type (4, "si"));  
    r.insert(map<int, string>::value_type (5, "wu"));  
    r.insert(map<int, string>::value_type (6, "liu"));  
    r.insert(map<int, string>::value_type (7, "qi"));  
    r.insert(map<int, string>::value_type (8, "ba"));  
    r.insert(map<int, string>::value_type (9, "jiu"));  
    //cout<<"Input";
    cin>>n;
    int i = 0;
    string j;

    //cout<<n.size()<<endl;
    for(i=0;i<n.size();i++){
       
        res = res + ((n.at(i)))-48;
        //cout<<n;
       
    }
    //cout<<res;
    re = re + r.at(res%10);
    res = res/10;
    while(res>0){
        i = res%10;
        j = r.at(i);
        re = j + " " + re;
        res = res/10; 
    }
    cout<<re;
    return 0;
}
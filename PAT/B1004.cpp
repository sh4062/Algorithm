#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n = 0,i = 0,max = 0,min= 999;
    string s1,s2,maxs,mins;
    cin>>n;
    while(n){
    cin>>s1;
    cin>>s2;
    cin>>i;
    if(i>max){max=i; maxs = s1 + " " + s2;}
    if(i<min){min = i;mins = s1 + " " + s2;}
    n--;
    }
    cout<<maxs<<endl;
    cout<<mins<<endl;

}
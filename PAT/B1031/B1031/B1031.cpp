#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char z[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
using namespace std;
int main(){
	vector<string> p;
	int n;
	cin>>n;
	while(n--){
		int d = 0;
string a;
cin>>a;
for(unsigned int i = 0;i<17;i++){
	d = d + (int(a[i])-48)*weight[i];

	
	}	d = d%11;
    //cout<<d<<(int(a[17])-48)<<endl;
if(a[17]!= z[d]){
	p.push_back(a);
}}
	
if(p.size()==0){cout<<"All passed"<<'\n';}
else{
for(int i = 0;i<p.size();i++){
cout<<p[i]<<'\n';	
}}
}


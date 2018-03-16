#include<iostream>
#include<string>
#include<map>
using namespace std;

char in (string s){
	char t ('T');
	for(unsigned int i = 2;i<s.length();i = i+4){
	if(s[i]==t) return s[i-2];}
	return 0;
}


int main(){
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	map < char,int> mp ;
	mp['A'] =1;
	mp['B'] =2;
	mp['C'] =3;
	mp['D'] =4;
	 int n;
	 cin>>n;
	 string t;
	 getline(cin,t);
	int res;
	string a;
	while(n--){
		getline(cin,a);
		res = mp[in(a)];
		//cout<<in(a);
		//cout<< mp['D'];
		cout<<res;
	
	
	}
	//fclose(stdin);
	//fclose(stdout);

}
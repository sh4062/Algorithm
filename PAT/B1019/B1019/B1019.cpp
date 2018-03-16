#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 4;
int r[maxn] = {0};
int a  = 0;
int b = 0; 
bool cmp1(int a1,int b1){
return a1> b1;}
bool cmp2(int a1,int b1){
return a1< b1;}

int s(int m){
		for(int i = 0;i<4;i++){
	    r[i] =m%10;
		
	    m = m /10;
	     }
    sort(r,r+4,cmp1);
	
	a = r[0]*1000+r[1]*100+r[2]*10+r[3];
	
	sort(r,r+4,cmp2);
	//cout<<r[3]<<endl;
	b = r[0]*1000+r[1]*100+r[2]*10+r[3];
	
	return a - b;
}

int main(){
	int n,t;
	cin>>n;
	t = n;
	for(int i = 0;i<4;i++){
	r[i] =t%10;
	t = t /10;
	}
	if(r[0] == r[1] && r[1]==r[2]&& r[2]==r[3]){
		a = r[0]*1000+r[1]*100+r[2]*10+r[3];
		printf("%04d - %04d = 0000\n", a,a);
		//cout<<n<<" - "<<n<<" = "<<"0000";
		return 0;
	}
	else{ while((s(n))!=6174){
		printf("%04d - %04d = %04d\n", a,b,a-b);
	    
		n = a-b;}
		printf("%04d - %04d = %04d\n", a,b,a-b);
	}
	
	}



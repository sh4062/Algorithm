#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int c[maxn] = {0};//root
int a[maxn] = {0};//people
int b[maxn] = {0};//interest



int findR(int x){
  if(a[x] == x) return x;
  else{int t = findR(a[x]);
       a[x] = t;
        return t;}
}

void Union(int a1,int b1){
a1 = findR(a1);
b1 = findR(b1);
if(a1!=b1) a[a1] = b1;}

bool cmp(int a, int b){
return a > b;}
int main(){
	int n,m,t;
	
	cin>>n;

	for(int i = 0;i <=n;i++) a[i] = i;
	for(int i = 1;i <=n;i++){
		cin>>m;
		getchar();
		for(int j = 1;j <= m;j++){
			cin>>t;
			if(b[t] == 0) b[t] = i;
			Union(i, findR(b[t]));
		
		}
	}

	for(int i = 1;i <=n;i++){
		c[findR(i)]++;
	}

	int res = 0;

	for(int i = 1;i <= n;i++){

	if(c[i] != 0)
	res++;}

	cout<<res<<"\n";
	sort(c + 1, c+n+1, cmp);
	for(int i = 1;i <= res;i++){
		cout<<c[i];
	    if(i < res) cout<<" ";}
}
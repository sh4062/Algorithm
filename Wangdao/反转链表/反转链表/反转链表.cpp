#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace  std;
const int maxn = 10005;
struct node{
	int a;
	int d;
	int b;
	
};


int main(){
	ios::sync_with_stdio(false);
	int s;
	cin>>s;
	int n;
	cin>>n;
	int m;
	cin>>m;

	vector<node> in(100000);
	vector<node> sort;
	vector<node> out;
	node temp;  
	for(int i = 0;i<n;i++){
	cin>>temp.a>>temp.d>>temp.b;
	in[temp.a]=temp;  
	}
	if(s == -1) //�׵�ַΪ-1.ֱ�����  
    {  
        printf("-1\n");  
	} else{
	int next = s; 
	while(next !=-1)  
        {  
            sort.push_back(in[next]);  
            next = in[next].b;  
        }  
	
	int right = m-1;  
        while(right < sort.size())//f��ת���
        {  
            for(int i=right;i>right-m;i--)  
            {  
                out.push_back(sort[i]);  
            }  
            right += m;  
        }  
        for(int i = right-m+1;i<sort.size() ;i++) //�����ұ�
        {  
             out.push_back(sort[i]);  
        }  
	for(int i =0;i<sort.size()-1;i++){
    out[i].b=out[i+1].a;
	printf("%05d %d %05d\n",out[i].a,out[i].d,out[i].b);}
	printf("%05d %d %d\n",out[sort.size()-1].a,out[sort.size()-1].d,-1);

	}
	


}
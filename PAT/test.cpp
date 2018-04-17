#include<iostream>  
#include<string.h>  
#include<vector>  
using namespace std;  
#define N 10001  
vector<int> edge[N];  
int deepest[N];  
int visited[N];  
int n;  
int  dfs(int now_node){  
    if(visited[now_node]==1)  
        return 0;  
    visited[now_node]=1;  
    if(edge[now_node].size()==0)  
        return 1;  
    int i,maxdeep=0,tmp;  
    for(i=0;i<edge[now_node].size();i++){//find a deepest from this node  
        if(visited[edge[now_node][i]]==0){  
            tmp=dfs(edge[now_node][i]);  
            maxdeep=maxdeep>tmp?maxdeep:tmp;  
        }  
    }  
    return maxdeep+1;  
}  
int main()  
{  
    int i,j;  
    cin>>n;  
    for(i=1;i<=n-1;i++){  
        int v1,v2;  
        cin>>v1>>v2;  
        edge[v1].push_back(v2);  
        edge[v2].push_back(v1);  
    }  
    memset(deepest,0,sizeof(deepest));  
    int max_deep=0;  
    int flag=0;  
    for(i=1;i<=n;i++){  
        if(0==flag)  
            memset(visited,0,sizeof(visited));  
        deepest[i]=dfs(i);  
        max_deep=max_deep>deepest[i]?max_deep:deepest[i];  
        for(j=i;j<=n;j++){//check if it is a connected graph  
            if(visited[j]==0){  
                flag++;  
                i=j-1;  
                break;  
            }  
        }  
    }  
    if(flag>0){  
        cout<<"Error: "<<flag+1<<" components"<<endl;  
    }  
 
    return 0;  
}  
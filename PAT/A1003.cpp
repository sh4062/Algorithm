#include<iostream>  
#include<string.h>
#include<cstdio>
#include<algorithm>  
#include<vector>  
using namespace std;
const int maxv = 510;
const int INF = 1000000000;
int n,m,st,ed,G[maxv][maxv],weight[maxv];
int d[maxv],w[maxv] = {0},num[maxv]= {0};
bool vis[maxv] = {0};

void Dijkstra(int s){
    fill(d,d+maxv,INF);
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for(int i = 0;i<n;i++){
        int u = -1,MIN = INF;
        for(int j = 0;j<n;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

    
        if(u == -1)return;
        vis[u] = true;
        for(int v = 0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u] + G[u][v]<d[v]){
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] +weight[v];
                    num[v] = num[u];
                }else if(d[u] + G[u][v]==d[v]){
                    if(w[u]+weight[v] > w[v]){
                         w[v] = w[u]+weight[v];
                    }num[v] += num[u];


                }
                
            }
    }



    }
    
    

}

int main(){
    cin>>n>>m>>st>>ed;
    for(int i = 0;i<n;i++){cin>>weight[i];}
    int u,v;
    fill(G[0],G[0]+maxv*maxv,INF);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        cin>>G[u][v];
        G[u][v] = G[v][u];
    }
    
    Dijkstra(st);
    cout<<num[ed]<<" "<<w[ed];

}


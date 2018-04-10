#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
const int maxv = 510;
const int INF = INT_MAX;
int n, m, st, ed, G[maxv][maxv], weight[maxv];
int dist[maxv], path[maxv] = {0}, num[maxv] = {0},w[maxv] = {0};
bool vis[maxv] = {0};

void Dijkstra(int s)
{   //初始化
    fill(dist, dist + maxv, INF);
    
    num[s] = 1;
    for (int i = 0; i < n; i++)
    {   w[i] = weight[i];
        dist[i] = G[s][i];
        if(G[s][i]<INF) {path[i] = s;w[i]=w[i]+w[s];}
        else path[i]=-1;
    }
    dist[s] = 0;
    for (int i = 0; i < n ; i++)//每次选择一个顶点,从原点通往这个顶点在通往其他剩余顶点的路径最短
    {   
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && dist[j] < MIN)
            {
                u = j;
                MIN = dist[j];
            }
        }

        if (u == -1)
            return;
        vis[u] = true;
        //已刚加入的顶点为中间点，对其他顶点的路径进行检测
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && G[u][v] != INF)
            {
                if (dist[u] + G[u][v] < dist[v])
                {
                    dist[v] = dist[u] + G[u][v];
                    path[v] = u;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }
                else if (dist[u] + G[u][v] == dist[v])
                {   num[v] += num[u];
                    if (w[u] + weight[v] > w[v])
                    {
                        w[v] = w[u] + weight[v];
                    }
                    
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> st >> ed;//城市/路/起点/终点
    for (int i = 0; i < n; i++)//救援队数目
    {
        cin >> weight[i];
    }
    int u, v;
    fill(G[0], G[0] + maxv * maxv, INF);
    for (int i = 0; i < m; i++)//路
    {
        cin >> u >> v;
        cin >> G[u][v];
        //cout << G[u][v]<<" ";
        G[v][u] = G[u][v];
        //cout << u<<v<<" ";
        //cout << G[u][v]<<" ";

    }

    Dijkstra(st);
    cout << num[ed] << " " << w[ed];
    //cout << G[0][2];
}

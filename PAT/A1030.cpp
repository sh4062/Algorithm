//1030. Travel Plan (30)
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int d;
    int c;
};
int N, M, S, D;
node G[505][505] = {0};
int visited[505] = {0};
int smallestcost = INT_MAX;
int smallestdist = INT_MAX;
int curdist = 0, curcost = 0;
vector<int> path;
vector<int> shortpath;
void dfs(int s)
{
    if (curdist > smallestdist)
        return;
    if (s == D)
    {
        if (curdist < smallestdist)
        {
            smallestdist = curdist;
            smallestcost = curcost;
            shortpath = path;
        }
        else if (curdist == smallestdist)
        {
            if (curcost < smallestcost)
            {
                smallestcost = curcost;
                smallestdist = curdist;
                shortpath = path;
            }
        }
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 1 || G[s][i].d == 0)
            continue;
        else
        {
            curcost += G[s][i].c;
            visited[i] = 1;
            path.push_back(i);
            curdist += G[s][i].d;
            dfs(i);
            path.pop_back(); //还原
            visited[i] = 0;
            curcost -= G[s][i].c;
            curdist -= G[s][i].d;
        }
    }
}

int main()
{     

    cin >> N >> M >> S >> D;
    while (M--)
    {
        int u, v, d, c;
        cin >> u >> v >> d >> c;
        G[u][v].d = d;
        G[v][u].d = d;
        G[u][v].c = c;
        G[v][u].c = c;
    }

    dfs(S);
    cout<<S<<" ";
    for (auto L : shortpath)
    {
        cout << L << " ";
    }
    cout << smallestdist << " ";
    cout << smallestcost;
}
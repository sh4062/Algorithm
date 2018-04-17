#include <bits/stdc++.h>
using namespace std;
//int G[10005][10005] = {0};//矩阵会tle
vector<int> G[10005];
int visited[10005] = {0};
int visited2[10005] = {0};
int n;
int maxd = 0;
set<int> res;
void dfs(int s, int depth)
{
    if (depth > maxd)
    {
        res.clear();
        res.insert(s);
        maxd = depth;
    }
    else if (depth == maxd)
    {
        res.insert(s);
    }
    //maxd = max(maxd, depth);
    visited[s] = 1;
    for (int i = 0; i < G[s].size(); i++)
    {
        if (visited[G[s][i]] == 0)
        {

            //cout << depth;

            dfs(G[s][i], depth + 1);
        }
    }
}

int main()
{

    cin >> n;
    int l = n - 1;
    while (l--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int components = 0;
    for (int i = 1; i <= n; i++)
    {

        if (visited[i] == 0)
        {
            dfs(i, 0);
            components++;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 1)
            visited[i] == 0;
    }
    if (components == 1)
    {

        dfs(1, 0);
        for (int j = 1; j <= n; j++)
        {

            visited[j] = 0;
        }
        set<int> tmp = res;

        auto i = tmp.begin();
        {

            dfs(*i, 0);
            for (int j = 1; j <= n; j++)
            {

                visited[j] = 0;
            }
        }
        for (auto i : tmp)
        {
            res.insert(i);
        }

        for (auto i : res)
        {
            printf("%d\n", i);
        }
        //cout << maxd << '\n';
    }

    else
        cout << "Error: " << components << " components";
}
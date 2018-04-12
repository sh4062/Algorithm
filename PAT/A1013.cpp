//1013. Battle Over Cities (25)
#include <bits/stdc++.h>
using namespace std;
int city[1111][1111];
int n, m, k, a;
bool visited[1111];
void dfs(int s)
{
    visited[s] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false && city[s][i] == 1)
            dfs(i);
    }
}
int main()
{

    cin >> n >> m >> k;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        city[u][v] = 1;
        city[v][u] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        fill(visited, visited + 1010, false);
        scanf("%d", &a);
        int cnt = 0;
        visited[a] = true;
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == false)
            {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}

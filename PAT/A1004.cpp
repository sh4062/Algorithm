#include <bits/stdc++.h>
using namespace std;
int maxdepth = -1;
// struct TN
// {
//     int level;
//     int k;
//     vector<int> child;
//     TN(int a, int b, vector<int> c)
//     {
//         level = a;
//         k = b;
//         child = c;
//     }
// };
void bfs()
{
    queue<int> q;
    q.push(1);
    level[1] = 0;
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        maxlevel = max(level[index], maxlevel);
        if (v[index].size() == 0)
            book[level[index]]++;
        for (int i = 0; i < v[index].size(); i++)
        {
            q.push(v[index][i]);
            level[v[index][i]] = level[index] + 1;
        }
    }
}
set<int> nl;
void dfs(vector<vector<int>> v, int index, int depth, vector<int> &res)
{
    if (nl.find(index) == nl.end())
    {
        res[depth]++;
        maxdepth = max(maxdepth, depth);
        return;
    }
    for (int i = 0; i < v[index].size(); i++)
    {

        dfs(v, v[index][i], depth + 1, res);
    }
}
int level[100], maxlevel = -1;
void bfs(vector<vector<int>> v, vector<int> &res)
{
    queue<int> q;
    q.push(1);
    level[1] = 0;
    while (!q.empty())
    {

        int index = q.front();
        q.pop();
        maxlevel = max(level[index], maxlevel);
        if (v[index].size() == 0)
            res[level[index]]++;
        for (int i = 0; i < v[index].size(); i++)
        {
            q.push(v[index][i]);
            level[v[index][i]] = level[index] + 1;
        }
    }
}

int main()
{
    int numofnode, numofnonleaf;
    cin >> numofnode >> numofnonleaf;
    vector<vector<int>> v(101);
    vector<int> res(numofnode);
    int level, k;
    for (int i = 0; i < numofnonleaf; i++)
    {
        cin >> level >> k;
        nl.insert(level);
        vector<int> tmp(k);
        for (int j = 0; j < k; j++)
        {
            cin >> tmp[j];
        }
        v[level] = (tmp);
        //TN n(level, k, tmp);
    }
    //cout<<"DFS";
    // dfs(v, 1, 0, res);
    bfs(v, res);
    //cout<<(nl.find(2)==nl.end());
    printf("%d", res[0]);
    // for (int i = 1; i <= maxdepth; i++)
    //     printf(" %d", res[i]);
    // return 0;
    for (int i = 1; i <= maxlevel; i++)
        printf(" %d", res[i]);
    return 0;
}

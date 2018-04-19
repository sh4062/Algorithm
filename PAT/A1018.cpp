//PAT 1018. Public Bike Management (30)
#include <bits/stdc++.h>
using namespace std;
int G[505][505];
int visit[505] = {0};
vector<int> B;
int Cm, N, Sp, M; //Cmax (<= 100), always an even number, is the maximum capacity of each station;
    //N (<= 500), the total number of stations;
    //Sp, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0);
    //and M, the number of roads.
    //有公共自行车网，从原点0出发到目标点sp，要把所有点的自行车数都置为half-full，找到最优路径，优先级依次为：路径长度最短，send最少，back最少。
vector<int> curpath;                      //当前路径
vector<int> shortpath;                    //最短路径
int minsend = INT_MAX, minback = INT_MAX; //发+回
int minlen = INT_MAX;
int cursend = 0, curback = 0;
int curlen = 0;
void dfs(int s)
{
    if (curlen > minlen)
        return; //不是最短路径返回
    if (s == Sp)
    {                        //到了Sp
        if (curlen < minlen) //路径长度最短
        {
            minlen = curlen;
            minsend = cursend;
            minback = curback;
            shortpath = curpath;
        }
        else if (curlen == minlen) //send最少，back最少。
        {
            if (cursend < minsend || (cursend == minsend && curback < minback))
            {
                minsend = cursend;
                minback = curback;
                shortpath = curpath;
            }
        }
        return;
    }
    for (int i = 1; i < N + 1; i++)
    { //DFS
        if (visit[i] == true || G[s][i] == INT_MAX)
            continue;
        int lastsend = cursend;
        int lastback = curback;
        if (B[i] + curback < (Cm / 2))
        { //可以送
            cursend +=( Cm / 2) - B[i] - curback;
            curback = 0;
        }
        else
        { //只能拿回
            curback = B[i] + curback - (Cm / 2);
        }
        visit[i] = 1;
        curpath.push_back(i);
        curlen += G[s][i];
        dfs(i);
        curpath.pop_back(); //还原
        visit[i] = 0;
        curlen -= G[s][i];
        cursend = lastsend;
        curback = lastback;
    }
}
int main()
{

    cin >> Cm >> N >> Sp >> M;
    int nn = N, mm = M;
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            G[i][j] = G[j][i] = INT_MAX;
        }
    }
    B.push_back(0);
    while (nn--)
    {
        int tmp;
        cin >> tmp;
        B.push_back(tmp);
    }
    while (mm--)
    {
        int u, v, w;    
        cin >> u >> v >> w;
        G[u][v] = w;
        G[v][u] = w;
    }
    dfs(0);
    printf("%d 0", minsend);
    for (int i = 0; i < shortpath.size(); i++)
    {
        printf("->%d", shortpath[i]);
    }
    printf(" %d", minback);
    return 0;
}
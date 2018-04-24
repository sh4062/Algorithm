//递归(0,0)->(m,n)动态规划
//存储路径dfs的实在不想拿c写了
//dp[0][0],dp[m][n] Ex 0,0->0,1||1,0   2 2 可以由 1 2 或者2 1 得到
//dp[m][n]=dp[m-1][n]+dp[m][n-1],dp[][]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int dp[100][100] = {0};

void path(int m, int n)
{

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    path(m, n);
    printf("%lld", dp[m][n]);
}
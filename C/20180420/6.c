//大正整数加法 
#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxN 11111
#define max(a, b) ((a) > (b) ? (a) : (b))
int a[maxN], b[maxN], c[maxN];
char s1[maxN], s2[maxN];
int main()
{
    int i, j, k, n, m;
    while (scanf("%s%s", s1, s2))
    {
        memset(c, 0, sizeof(c));
        n = strlen(s1);
        m = strlen(s2);
        for (i = 0; i < n; i++) //从尾部开始加111+999=1110
            a[i] = s1[n - i - 1] - '0';
        for (i = 0; i < m; i++)
            b[i] = s2[m - i - 1] - '0';
        k = max(n, m);
        for (i = 0; i <= k; i++)//进位
        {
            c[i] += a[i] + b[i];
            if (c[i] > 9)
            {
                c[i + 1]++;
                c[i] %= 10;
            }
        }
        //防止前面0开头
        i = k;
        while (c[i] == 0)
            i--;
        if (i < 0)
            printf("???0");
        else
        {
            for (; i >= 0; i--)
                printf("%d", c[i]);
        }
    }
}

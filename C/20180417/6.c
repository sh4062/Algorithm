//给定一个n个整型元素的数组a，其中有一个元素出现次数超过n / 2，求这个元素。
//用hash空间非最优
//该数出现的次数为x，则x满足，n/2+1<=x<=n;所以我们可以想到如果该数和其余的数全部相抵消的话，至少还剩1个
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[9] = {1, 2, 2, 2, 2, 2, 3, 8, 9};
    int res = a[0];
    int cnt = 0;
    for (int i = 0; i < 9; i++)
    {
        if (cnt == 0)
        {
            res = a[i];
            cnt = 1;
        }
        else
        {
            if (res == a[i])
                cnt++;
            else
                cnt--;
        }
    }

    printf("%d", res);
}
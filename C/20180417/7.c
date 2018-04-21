//给定一个含有n个元素的整型数组，找出数组中的两个元素x和y使得abs(x - y)值最小
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[9] = {1, 2, 2, 3, 4, 15, 3, 8, 9};
    int res = 999999;
    int cnt = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {

            if (res > abs(a[i] - a[j]))
            {
                res = abs(a[i] - a[j]);
            }
        }
    }

    printf("%d", res);
}
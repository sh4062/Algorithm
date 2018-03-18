#include <stdio.h>

int main()
{
    int a[200000] = {0}, n = 0, tmp, sum = 0, max = 0, result = 0;
    // 题目中只说骑行公里数为非负，却没说多大，这里的200000是通过提交试出来的
    scanf("%d", &n);

    for (int i = 0; i < n; i++, a[tmp]++) { // 读取每日骑行公里数，在对应位累计天数
        scanf("%d", &tmp);
        if (tmp > max) max = tmp;           // 这里判断最大值，记录骑行的最大公里数
    }

    for (int i = 0; i <= max; i++) {        // 遍历记录表，到最大公里数为止
        tmp = i;                            // 当前查询的公里数
        sum += a[i];                        // 小于等于当前公里数的天数
        if (tmp <= n - sum)                 // 大于当前公里数的天数如果比当前公里数大
            result = tmp;                   // 符合条件记录结果
        else
            break;                          // 不符合条件退出循环
    }

    printf("%d", result);                   // 输出结果
    return 0;
}
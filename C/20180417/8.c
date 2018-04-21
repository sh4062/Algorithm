#include <stdio.h>
//给定含有1001个元素的数组，其中存放了1-1000之内的整数，只有一个整数是重复的，请找出这个数
//A1 + … + A1001 – (1 + …+ 1000)
//XOR
int main()
{
    int a[1001];
    for (int i = 1; i <= 1000; i++)
        a[i] = i;
    a[3] = 1;
    //x^x=0，x^0=x
    int xor = a[1];

    for (int i = 2; i <= 1000; i++)
    {
        xor ^= a[i];
        xor ^= i;
    }

    printf("%d", xor);
}
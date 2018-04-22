//有101个整数，其中有50个数出现了两次，1个数出现了一次， 找出出现了一次的那个数。
//有102个整数，其中有50个数出现了两次，2个数出现了一次， 找出出现了一次的那2个数。
//有103个整数，其中有50个数出现了两次，3个数出现了一次， 找出出现了一次的那3个数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fun1(int a[]) //异或呗
{
    int aa = a[0];
    for (int i = 1; i < 101; i++)
    {
        aa ^= a[i];
    }
    return aa;
}
int *fun2(int a[]) //剑指offer异或
/*  所有数异或得到两个单独数a,b的异或值c，
    指出c为1的某位。
    根据pos位为1或者为0将数组划分为两个组，
    再分别对这两个组进行异或，
    即可得到：a,b。*/
{
    static int res[2];
    int ret = 0;
    int pos = 0, i = 0;
    int num1 = 0;
    int num2 = 0;
    for (i = 0; i < 102; i++)
    {
        ret ^= a[i];
    }
    for (i = 0; i < 32; i++)
    {
        if (((ret >> 1) & 1) == 1)
        {
            pos = i;
            break;
        }
    }
    for (i = 0; i < 102; i++)
    {
        if (((a[i] >> pos) & 1) == 1)

        {
            num1 ^= a[i];
        }
    }
    num2 = num1 ^ ret;
    res[0] = num1;
    res[1] = num2;
    return res;
}

int *fun3(int a[])
{ //。。。查了下用异或也能做 算了直接hash吧
    int hash[1111111];
    static int res[3];
    for (int i = 0; i < 5; i++)
    {
        hash[a[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (hash[a[i]] == 1)
        {
            res[cnt] = a[i];
            cnt++;
        }
    }
    return res;
}
int main()
{
    int a[5] = {1, 2, 3, 4, 4};
    int *res = fun3(a);
    printf("%d %d %d", res[0], res[1], res[2]);
}
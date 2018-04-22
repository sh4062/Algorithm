//3. 进制转换
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*将10进制转换为k进制 */
void fun1(int n, int k)
{
    if (n / k)
        fun1(n / k, k);
    int i = n % k;
    if (k <= 10)
        putchar('0' + i);
    else if (k > 10)
        if (i < 10)
            putchar('0' + i);
        else
            putchar('A' + i - 10);
}

/*将k进制转换为10进制 */
int fun2(char *str, int k)
{
    int num = 0;
    while (*str != '\0')
    {
        char ch = *str;
        if (ch >= '0' && ch <= '9')
            if ((ch - '0') < k)
                num = num * k + ch - '0';
        if (ch >= 'a' && ch <= 'z')
            if ((ch - 'a' + 10) < k)
                num = num * k + 10 + ch - 'a';
        if (ch >= 'A' && ch <= 'Z')
            if ((ch - 'A' + 10) < k)
                num = num * k + 10 + ch - 'A';
        str++;
    }
    return num;
}
int main()
{
    char *a="AA";
    int res = fun2(a,16);
    printf("%d",res);
    
}
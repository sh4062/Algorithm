//1. 从键盘上输入字符，将小写字母转换成大写字母。输入“ctl + z” 结束 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *a = (char *)malloc(10);

    // gets(a);
    while (scanf("%s", a) != EOF)
    {
        for (int i = 0; i < 10; i++)
        {
            if (a[i] >= 'a' && a[i] <= 'z')
            {
                a[i] = a[i] - 32;
            }
        }
        printf("%s\n", a);
    }
}
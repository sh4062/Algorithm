//2. 将 字 符 串 中 的 空 格 替 换 成 “%020” ， 例 如 “hello world how ”
//”hello%020%020%020world%020%020%020how%020%020%020%020”
//剑指offer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100] = "Hello World !!! .";
    int i = 0;
    int j = 0;
    int len = 0;
    int count = 0;
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
    }
    i = len;
    j = 3 * count + len;
    while (i != j && i >= 0)
    {
        if (s[i] == ' ')
        {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '0';
            s[j] = '%';
        }
        else
        {
            s[j] = s[i];
        }
        j--;
        i--;
    }
    len = strlen(s);
    for (i = 0; i < len; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}

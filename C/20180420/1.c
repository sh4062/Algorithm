//1. 将包含字符数字的字符串分开,使得分开后的字符串前一部分是数字后一部分是字母
//也许用partition做更明智？Segmentation fault (core dumped)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int slen = 10;
    char *a = "h1ell2o3";
    char *p = (char *)malloc(sizeof(char) * strlen(a));
    // gets(a);
    int cnt = 0;
    char * x = a;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            p[cnt] = a[i];
            cnt++;
        }
    }
    for (int i = 0 ; i < strlen(a); i++)
    {
        if (a[i] <= '0' || a[i] >= '9')
        {
            p[cnt] = a[i];
            cnt++;
        }

    }
    

    printf("%s", p);
}
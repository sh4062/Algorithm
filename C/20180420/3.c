//3. 删除字符串中指定的字符
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()

{

    char s[100], *p, *q;
    char d;
    gets(s);
    d = getchar();

    for (p = s, q = s; *p != '\0'; p++)
        if (*p != d)
        {
            *q = *p; //改变s
            q++;
        }

    *q = *p; //p=\0

    puts(s);
}
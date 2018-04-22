//将 字 符 串 中 的 相 邻 的 多 余 空 格 去 掉
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void delete (char c[])
{
    int cnt = 2;
    char *tmp = (char*)malloc(200*sizeof(char));
    strcpy(tmp, c);
    int i = 0;
    while (*tmp != '\0')
    {  if (*tmp != ' ')
        {  
            c[i++] = *tmp;
            
            cnt = 0;
        }
        else
        {
            cnt++;
            if (cnt == 1)
                c[i++] = ' ';
            
        }
        tmp++;
    }
    c[i-1] = '\0';
    printf("%s", c);
}

int main()
{
    char a[] = {"   hello    world   how are you  asd asd    asd   "};

    delete(a);
    
    return 0;
}
//删除一个数组中重复的元素(有序数组？？？)
//真的是越来越不喜欢指针了 这辈子不想写c了 没有stl要死了
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void deletel(int a[])
{
    int cnt = 1;
    int *p = a, *q = a;
    p++;
    for (; *p != '\0'; p++)//握草 为什么整形数组也能用\0判断
    {
        if (*q != *p)
        {
            q++;
            cnt++;
            *q = *p;
        }
    }
    q++;
    *q = *p;

    for (int i = 0; i < cnt; i++)
    {
        printf("%3d",  a[i]);
    }
}

int main()
{
    int a[] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6};

    deletel(a);

    return 0;
}
/*有一个学生结构体,其数据成员有: 学号, 姓名, 3 门课程。从键盘上输入 5 个学生
的信息。要求输出:
按照学号递增输出全部学生信息,每个学生的信息一行。
(格式: 学号 姓名 分数
1 分数 2 分数 3 总分)
(2) 输出每门课程最高分的学生的信息
(3) 输出每门课程的平均分
(4) 按照总分输出学生排名*/
/*
5 m 7 4 4
4 n 4 5 6
1 b 5 4 2
2 v 1 3 4
3 c 5 6 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int id;
    char name[20];
    int c1;
    int c2;
    int c3;

} student;
int Comp(const void *p1, const void *p2)
{
    return (*(student *)p2).id < (*(student *)p1).id ? 1 : -1;
}
int CompSum(const void *p1, const void *p2)
{
    return ((*(student *)p2).c1 + (*(student *)p2).c2 + (*(student *)p2).c3) > ((*(student *)p1).c1 + (*(student *)p1).c2 + (*(student *)p1).c3) ? 1 : -1;
}
int main()
{
    student a[100];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d %s %d %d %d", &a[i].id, a[i].name, &a[i].c1, &a[i].c2, &a[i].c3);
    }
    qsort(a, 5, sizeof(a[0]), Comp);
    for (int i = 0; i < 5; i++)
    {
        printf("学号递增输 %d %s %d %d %d\n", a[i].id, a[i].name, a[i].c1, a[i].c2, a[i].c3);
    }
    int max1 = 0, max2 = 0, max3 = 0;
    int max1i = 0, max2i = 0, max3i = 0;
    for (int i = 0; i < 5; i++) //懒得写了 assert没有重复的
    {
        if (max1 < a[i].c1)
        {
            max1 = a[i].c1;
            max1i = i;
        }
        if (max2 < a[i].c2)
        {
            max2 = a[i].c2;
            max2i = i;
        }
        if (max3 < a[i].c3)
        {
            max3 = a[i].c3;
            max3i = i;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (i == max1i)
            printf("每门课程最高分1 %d %s %d %d %d\n", a[i].id, a[i].name, a[i].c1, a[i].c2, a[i].c3);
        if (i == max2i)
            printf("每门课程最高分2 %d %s %d %d %d\n", a[i].id, a[i].name, a[i].c1, a[i].c2, a[i].c3);
        if (i == max3i)
            printf("每门课程最高分3 %d %s %d %d %d\n", a[i].id, a[i].name, a[i].c1, a[i].c2, a[i].c3);
    }
    int avg1 = 0, avg2 = 0, avg3 = 0;
    for (int i = 0; i < 5; i++)
    {
        avg1 += a[i].c1;
        avg2 += a[i].c2;
        avg3 += a[i].c3;
    }
    printf("平均分1 %d\n", avg1 / 5);
    printf("平均分2 %d\n", avg2 / 5);
    printf("平均分3 %d\n", avg3 / 5);
    qsort(a, 5, sizeof(a[0]), CompSum);
    for (int i = 0; i < 5; i++)
    {
        printf("按照总分输出学生排名 %d %s %d %d %d\n", a[i].id, a[i].name, a[i].c1, a[i].c2, a[i].c3);
    }
}
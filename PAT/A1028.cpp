//1028. List Sorting (25)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct stu
{
    char id[10];
    char name[10];
    int grade;
} a[100010];

bool cmp1(stu x, stu y)
{
    return strcmp(x.id, y.id) < 0;
}

bool cmp2(stu x, stu y)
{
    if (strcmp(x.name, y.name) != 0)
        return strcmp(x.name, y.name) < 0;
    else
        return strcmp(x.id, y.id) < 0;
}

bool cmp3(stu x, stu y)
{
    if (x.grade != y.grade)
        return x.grade < y.grade;
    else
        return strcmp(x.id, y.id) < 0;
}

int main()
{
    int i, n, c;
    scanf("%d%d", &n, &c);
    for (i = 0; i < n; i++)
    {
        scanf("%s%s%d", a[i].id, a[i].name, &a[i].grade);
    }
    if (c == 1)
        sort(a, a + n, cmp1);
    else if (c == 2)
        sort(a, a + n, cmp2);
    else if (c == 3)
        sort(a, a + n, cmp3);
    for (i = 0; i < n; i++)
    {
        printf("%s %s %d\n", a[i].id, a[i].name, a[i].grade);
    }
    return 0;
}
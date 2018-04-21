//选择排序？BFPTR最优 最差(n)
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int max = a[0], max2nd = a[0];
    int maxi = 0;
    for (int i = 0; i < 9; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            maxi = i;
        }
    }
    int tmp = a[0];
    a[0] = a[maxi];
    a[maxi] = tmp;
    for (int i = 1; i < 9; i++)
    {
        if (max2nd < a[i])
        {
            max2nd = a[i];
        }
    }
    printf("1st : %d,2nd : %d", max, max2nd);
}
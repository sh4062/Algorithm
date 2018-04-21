#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int b[] = {4, 3, 2, 1, 0, 1, 2, 3, 4};
    int c[] = {0, 1, 3, 5, 7, 5, 3, 1, 0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < b[i]; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < a[i] - 1; j++)
        {
            printf("* ");
        }

        printf("*\n");
    }
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < b[i]; j++)
        {
            printf(" ");
        }
        printf("*");
        for (int j = 0; j < c[i]; j++)
        {
            printf(" ");
        }
        if (i == 0 || i == 8)
            printf("\n");
        if (i != 0 && i != 8)

            printf("*\n");
    }
    printf("\n");
    int aa = 19, bb = 4, cc = 2, dd = 2, ee = 9;
    while (bb)
    {
        for (int i = 0; i < bb; i++)
            printf(" ");
        for (int i = 0; i < cc; i++)
            printf("* ");
        for (int i = 0; i < bb - 1; i++)
            printf("  ");
        for (int i = 0; i < cc; i++)
            printf("* ");
        for (int i = 0; i < bb - 1; i++)
            printf(" ");
        printf("\n");
        cc++;
        bb--;
    }
    aa--;
    while (ee > 0)
    {
        for (int i = 0; i < dd; i++)
            printf(" ");
        for (int i = 0; i < ee; i++)
            printf("* ");
        printf("\n");
        ee = ee - 2;
        dd = dd + 2;
    }
}
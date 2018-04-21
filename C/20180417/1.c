//*
#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d*%d=%d ", a[j], a[i], a[i] * a[j]);
            if (j == i)
                printf("\n");
        }
    }
}
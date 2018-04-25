#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

void is(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int ival = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] >= ival)
            {
                a[j + 1] = a[j];
            }
            else
            {

                break;
            }
        }
        a[j + 1] = ival;
    }
}

int main()
{
    int a[10] = {0};
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        a[i] = (rand()) % 10;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", a[i]);
    }
    is(a, 10);
    printf("\n-----------------------------------------------\n ");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", a[i]);
    }
}
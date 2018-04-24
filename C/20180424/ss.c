#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

void ss(int *a, int len)
{

    for (int i = 0; i < len; i++)
    {
        int min = 99999999, mini = -1;
        for (int j = i; j < len; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                mini = j;
            }
        }
        SWAP(a[mini], a[i]);
    }
}

int main()
{
    int a[111] = {0};
    srand(time(NULL));
    for (int i = 0; i < 111; i++)
    {
        a[i] = (rand()) % 111;
    }
    for (int i = 0; i < 111; i++)
    {
        printf("%2d ", a[i]);
    }
    ss(a, 111);
    printf("\n------------------ss-----------------------------\n ");
    for (int i = 0; i < 111; i++)
    {
        printf("%2d ", a[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }
int partition(int *a, int left, int right)
{
    int i = left, k = left;
    for (i; i < right; i++)
    {
        if (a[i] < a[right])
        {
            SWAP(a[k], a[i]);

            k++;
        }
    }
    SWAP(a[k], a[right]);
    return k;
}

void qs(int *a, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(a, left, right);
        qs(a, left, pivot - 1);
        qs(a, pivot + 1, right);
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
    qs(a, 0, 110);
     printf("\n-----------------------------------------------\n ");
    for (int i = 0; i < 111; i++)
    {
        printf("%2d ", a[i]);
    }
}
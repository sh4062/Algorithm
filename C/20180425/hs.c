#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }
void adjustheap(int *a, int n, int k)
{
    int tmp = a[k];
    int i = 2 * k + 1;
    while (i < n)
    {
        if (i + 1 < n && a[i + 1] > a[i])
            i++;
        if (a[i] > tmp)//!tmp
        {
            a[k] = a[i];
            k = i;
            i = 2 * k + 1;
        }
        else
        {
            break;
        }
    }
    a[k] = tmp;
}
void hs(int a[], int n)
{

    for (int i = n / 2; i >= 0; --i)
        adjustheap(a, n, i); //初始堆
    
    for (int i = n - 1; i > 0; --i)//排序
    {
        SWAP(a[0], a[i]);
        adjustheap(a, i, 0);
    }
}

int main()
{
    int a[5] = {0};
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        a[i] = (rand()) % 5;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%2d ", a[i]);
    }
    hs(a, 5);
    printf("\n-----------------------------------------------\n ");
    for (int i = 0; i < 5; i++)
    {
        printf("%2d ", a[i]);
    }
}
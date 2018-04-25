#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

int cmp(const void *p1, const void *p2)
{
    return (*(int *)p1) > (*(int *)p2) ? 1 : -1;
}
int main()
{
    int a[500000] = {0};
    srand(time(NULL));
    for (int i = 0; i < 500000; i++)
    {
        a[i] = (rand()) % 444444;
    }
    // for (int i = 0; i < 500000; i++)
    // {
    //     printf("%2d ", a[i]);
    // }
    qsort(a, 500000, sizeof(int), cmp);
    printf("\n-----------------------------------------------\n ");
    for (int i = 420000; i < 422000; i++)
    {
        printf("%2d ", a[i]);
    }
}
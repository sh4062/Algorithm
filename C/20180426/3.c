//计数排序
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void countSort(int array[], int size)
{
    assert(array != NULL && size > 0);

    //计数数组，用于统计数组array中各个不同数出现的次数
    int *countArray = (int *)calloc(100 /*max*/, sizeof(int));
    //用于存放已经有序的数列
    int *sortedArray = (int *)calloc(size, sizeof(int));

    //统计数组array中各个不同数出现的次数，循环结束后countArray[i]表示数值i在array中出现的次数
    int index = 0;
    for (index = 0; index < size; ++index)
    {
        countArray[array[index]]++;
    }

    //统计数值比index小的数的个数，循环结束之后countArray[i]表示array中小于等于数值i的元素个数
    for (index = 1; index < 100/*max*/; ++index)
    {
        countArray[index] += countArray[index - 1];
    }

    for (index = size - 1; index >= 0; --index)
    {
        //因为数组的起始下标为0，所以要减一
        sortedArray[countArray[array[index]] - 1] = array[index];
        //这里减一是为了保证当有多个值为array[index]的元素时，后出现的值为array[index]的元素
        //放在后面，也就是为了保证排序的稳定性
        --countArray[array[index]];
    }

    memcpy(array, sortedArray, size * sizeof(int));
    free(sortedArray);
    free(countArray);
}

int main()
{
    int a[10] = {0};
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        a[i] = (rand()) % 100;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", a[i]);
    }
    countSort(a, 10);
    printf("\n-----------------------------------------------\n ");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", a[i]);
    }
}
//0139762533
//1113011101
//12366789910
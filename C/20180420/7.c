//求一个字符串数组的最大值和次大值
//二级指针
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void big(char *arr[], int size, char *big1, char *big2) //不用二级指针 需要交换信息 如果内容很大的话大概会慢
{
    int i;
    for (i = 0; i < size; i++) //逐个比较
    {
        if (strcmp(big1, arr[i]) <= 0) //最大比某个小
        {
            strcpy(big2, big1);   //最大->次大
            strcpy(big1, arr[i]); //a1->最大
        }

        if (strcmp(big2, arr[i]) < 0 && strcmp(big1, arr[i]) > 0) //次大比某个小
        {
            strcpy(big2, arr[i]);
        }
    }
}
void big2p(char *arr[], int size, char **big1, char **big2) //二级指针 交换指针 传进去什么就操作什么！！!
{
    *big1 = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (strcmp(*big1, arr[i]) < 0)
        {

            char *tmp = *big1;
            *big1 = arr[i];
            arr[i] = tmp;
        }
    }

    for (int i = 1; i < size; i++)
    {
        if (strcmp(*big2, arr[i]) < 1)
        {
            char *tmp = (char *)malloc(sizeof(char) * 100);
            tmp = *big2;
            *big2 = arr[i];
            arr[i] = tmp;
        }
    }
}
int main()
{
    char *arr[100];

    int size;
    int i;

    char *big1 = (char *)malloc(sizeof(char) * 100);
    char *big2 = (char *)malloc(sizeof(char) * 100);
    // big1[0] = '\0';
    // big2[0] = '\0';
    // char **big3 = (char **)malloc(sizeof(char *) * 100);
    // char **big4 = (char **)malloc(sizeof(char *) * 100);

    // printf("Input ths size of string :\n");
    // scanf("%d", &size);

    // printf("Input %d strings:\n", size);
    // for (i = 0; i <= size; i++)
    // {
    //     arr[i] = (char *)malloc(sizeof(char) * 100);
    //     fflush(stdin); //清除数据刚进来时缓冲区数据，防止被gets
    //     gets(arr[i]);  //
    // }
    // big3 = arr;
    // big4 = arr;
    // big(arr, size, big1, big2);

    char *b[10] = {"lele", "lili", "lilei", "hanmeimei", "zhousi", "sadsad", "aaa", "bb", "cc", "cewv"};
    // big(b, 5, big1, big2);
    big2p(b, 10, &big1, &big2);
    printf("???\n");

    printf("max = %s, max2nd = %s\n", big1, big2);
}
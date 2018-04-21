//求n个有序数组的公共元素。
#include <stdio.h>
#include <stdlib.h>
#define Len 6
//hash

void overlap2(int array1[], int array2[])
{
    
    int i = 0, j = 0;
    while (i < Len && j < Len)
    {
        if (array1[i] > array2[j])
            j++;
        else if (array1[i] < array2[j])
            i++;
        else if (array1[i] == array2[j])
        {
            printf("%d", array1[i]);
            i++;
            j++;
        }
    }
}

void overlap3(int array1[], int array2[],int store[])
{
    int array[Len];
    int cnt = 0;
    int i = 0, j = 0,k=0;
    while (i < Len && j < Len  )
    {
        if (array1[i] > array2[j])
            j++;
        else if (array1[i] < array2[j])
            i++;
        else if (array1[i] == array2[j])
        {
            store[cnt++]=array1[i];
            i++;
            j++;
        }
    }
    while(cnt<Len){
        store[cnt++]=9999;

    }
}
int main()
{
    int a[6] = {1, 2, 3, 4,5, 6};
    int b[6] = {1, 2, 3, 4, 5, 7};
    int c[6] = { 1, 3, 4, 5,6, 7};
    overlap2(a,b);
     printf("\n");
    int t[6]={0}  ,tt[6]={0};
     overlap3(a,b,t);
     
     for(int i =0;i<6;i++){
         if(t[i]!=9999)
         printf("%d",t[i]);
     }
     overlap3(t,c,tt);
     printf("\n");
     for(int i =0;i<6;i++){
         if(tt[i]!=9999)
         printf("%d",tt[i]);
     }
}
#include <stdio.h>
#include <math.h>
#define swap(a, b) ({int c =a;a=b;b=c; })
#define min(a, b) \
        ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
int FindKthInTwoSortedArray(int array1[], int len1, int array2[], int len2, int k)
{
        if (k <= 0)
        {
                printf("Invalid k ");
                return -1;
        }
        
        if (len1 > len2)
                return FindKthInTwoSortedArray(array2, len2, array1, len1, k);
        if (len1 == 0)
                return array2[len2 - k];
        if (k == 1)
                return ((array1[len1 - 1] > array2[len2 - 1]) ? array1[len1 - 1] : array2[len2 - 1]);

       

        int num1 = len1 - (k) / 2 >= 0 ? len1 - (k)/ 2 : 0;

        int num2 = len2 -k+ (len1 - num1);
        if (array1[num1 ] == array2[num2 ])

                return array1[num1 ];
        else if (array1[num1] > array2[num2 ])
        {

                return FindKthInTwoSortedArray(array1, num1, array2, len2, k + num1 - len1);
        }

        else if (array1[num1 ] < array2[num2 ])

        {
                return FindKthInTwoSortedArray(array1, len1, array2, num2, k - len2 + num2);
        }
}


int main()
{
        // int alen = 5;
        // int blen = 5;
        // int a[5] = {1, 2, 3, 4, 5};
        // int b[5] = {1, 2, 5, 6, 7};
        int alen = 11;
        int blen = 11;
        int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 17};
        //int b[11] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 29};
        int b[11] = {22,23,24,25,26,27,88,99,111,999,1111};  
         for (int i = 1; i <= 10; i++)
        {
                int res = FindKthInTwoSortedArray(a, alen, b, blen,i);
                printf("%d ", res);
       }
}
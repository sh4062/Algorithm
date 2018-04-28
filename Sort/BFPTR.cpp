#include <bits/stdc++.h> //TopK
using namespace std;

int BFPRT(int array[], int left, int right, const int &k);

int InsertSort(int array[], int left, int right) //返回中位数下标的插入排序
{
    int Ival, i, j;
    for (i = left + 1; i <= right; i++)
    {
        Ival = array[i];
        j = i - 1;
        while (j >= left && array[j] > Ival)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = Ival;
    }
    return ((right - left) >> 1) + left;
}
int Partition(int array[], int left, int right, int pivot_index) //!多了一个pivot_index 指定主元的Part~
{
    swap(array[pivot_index], array[right]); // 把主元放置于末尾
    int divide_index = left;                // 跟踪划分的分界线

    for (int i = left; i < right; i++)
    {
        if (array[i] < array[right])
            swap(array[divide_index++], array[i]); // 比主元小的都放在左侧
    }

    swap(array[divide_index], array[right]); // 最后把主元换回来

    return divide_index;
}

int GetPivotIndex(int array[], int left, int right) //返回中位数的中位数的下标
{
    if (right - left < 5)//小于5直接选择排序
        return InsertSort(array, left, right);

    int sub_right = left - 1;//第一个替换的位置

    for (int i = left; i + 4 <= right; i += 5)//每5个元素插入排序一次
    {
        int index = InsertSort(array, i, i + 4); //排序并找到五个元素的中位数的下标
        sub_right=sub_right+1;
        swap(array[sub_right], array[index]);  // 把中位数依次放在左侧
    }

    return BFPRT(array, left, sub_right, ((sub_right - left + 1) >> 1) + 1);//比如 12345678->37245618 sub=1 l=0 1+1=2
}
int BFPRT(int array[], int left, int right, const int &k)
{
    int pivot_index = GetPivotIndex(array, left, right);           //中位数的中位数的下标
    int divide_index = Partition(array, left, right, pivot_index); // 根据中文数的中位数进行划分，返回划分边界
    int num = divide_index - left + 1;//num是第num大的数

    if (num == k)//递归边界
        return divide_index;
    else if (num > k)//高低位
        return BFPRT(array, left, divide_index - 1, k);
    else
        return BFPRT(array, divide_index + 1, right, k - num);
}

int main()
{
    int k = 3;
    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    cout << "原数组：";
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";
    cout << endl;

    cout << "第" << k << "小值为：" << array[BFPRT(array, 0, 9, k)] << endl;

    cout << "变换后的数组：";
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}

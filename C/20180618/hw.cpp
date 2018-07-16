// 迭代器的种类有哪些？各自的功能是什么？
// 	5种迭代器：随机访问迭代器(RandomAccessIterator),双向迭代器(BidirectionalIterator),前向迭代器(ForwardIterator),输出迭代器(OutputIterator),输入迭代器(InputIterator)
// 	输入迭代器：从容器中读取元素。输入迭代器只能一次读入一个元素向前移动，输入迭代器只支持一遍算法，同一个输入迭代器不能两遍遍历一个序列
// 	输出迭代器：向容器中写入元素。输出迭代器只能一次一个元素向前移动。输出迭代器只支持一遍算法，同一个输出迭代器不能两次遍历一个序列
// 	前向迭代器：拥有输入迭代器和输出迭代器的功能，并保留在容器中的位置
// 	双向迭代器：拥有前向迭代器和逆向迭代器的功能，支持多遍算法
// 	随机访问迭代器：拥有双向迭代器的功能，可以直接访问容器中的任何元素
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Compare = std::less<T>>
class HeapSort
{
  public:
    HeapSort(T *arr, int size);
    void heapAdjust(int i, int j, T *arr);
    void sort();

  private:
    T *_arr;
    int _size;
};

template <typename T, typename Compare>
HeapSort<T, Compare>::HeapSort(T *arr, int size)
: _arr(arr)
, _size(size)
{
    cout << "HeapSort\n";
}
template <typename T, typename Compare>
void HeapSort<T, Compare>::heapAdjust(int i, int j, T *arr)
{
    int tmp = arr[i];
    int k = 2 * i + 1;

    for (k; k < j; k = 2 * k + 1)
    {

        if (k + 1 < j && arr[k] < arr[k + 1])
        {
            k++;
        }

        if (arr[k] > tmp)
        {
            arr[i] = arr[k];
            i = k;
        }
        else
            break;
    }
    arr[i] = tmp;
}

template <typename T, typename Compare>
void HeapSort<T, Compare>::sort()
{
    for (int i = _size / 2 - 1; i >= 0; i--)
    {
        heapAdjust(i, _size, _arr);
    }

    for (int i = _size - 1; i > 0; i--)
    {
        swap(_arr[0], _arr[i]);
        heapAdjust(0, i, _arr);
    }
}

int main()
{
    int array[8] = {8, 1, 14, 3, 21, 5, 7, 10};
    HeapSort<int> h(array, 8);
    h.sort();
    for (auto i : array)
        cout << i << " ";
}
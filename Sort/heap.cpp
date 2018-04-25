//heap sort 建立大顶堆 然后排序
#include <bits/stdc++.h>
using namespace std;
void print(const std::vector<int> &L)
{
    for (auto i : L)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void Sift(vector<int> &L, int len, int k)
{
    int i = 2 * k + 1; //i是k的左孩子
    int tmp = L[k];
    while (i < len)
    {
        if (i + 1 < len && L[i] < L[i + 1]) //右孩子比较大则i为右孩子
            ++i;

        if (tmp < L[i])//将ij调换且调整ij以便继续调整
        {
            L[k] = L[i];
            k = i;
            i = 2 * k + 1;
        }
        else
            break;
    }
    L[k] = tmp;//被调整的值放入最终位置
}
void HeapSort(vector<int> &L)
{
    int len = L.size();
    int tmp;
    for (int i = len / 2 ; i >= 0; --i)
        Sift(L, len, i); //初始堆
    print(L);
    for (int i = len - 1; i > 0; --i)
    {
        swap(L[0], L[i]);
        Sift(L, i, 0);
    }
}
int main()
{
    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4, 999};
    HeapSort(L);
    std::cout << "result : ";
    print(L);
}

//Insertion sort
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
void InsertSort(vector<int> &L)
{
    int len = L.size();
    int p = L[0];//一个显然是排序好的
    int i, j;
    for (int i = 1; i < len; i++)
    {
        int p = L[i];//即将插入的变量
        j = i - 1;//已排序部分长度
        while (j >= 0 && p < L[j])//从右向左搜索 若比p大则后移
        {
            L[j+1] =L[j];//后移动
            j--;
        }
        L[j+1] = p;//插入
    }
}
int main()
{
    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4,999};
    InsertSort(L);
    std::cout << "result : ";
    print(L);
}
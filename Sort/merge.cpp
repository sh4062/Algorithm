//Merge sort.
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
void merge(vector<int> &L, int low, int mid, int high)
{
    vector<int> vec1(L.begin() + low, L.begin() + mid + 1);
    vector<int> vec2(L.begin() + mid + 1, L.begin() + high + 1);
    vec1.push_back(INT_MAX);
    vec2.push_back(INT_MAX);
    int i = 0;
    int j = 0;
    for (int k = low; k <= high; k++)
    {
        if (vec1[i] < vec2[j])
        {
            L[k] = vec1[i];
            i++;
        }
        else
        {
            L[k] = vec2[j];
            j++;
        }
    }
}
void ms(vector<int> &L, int low, int high)
{
    if (low < high)
    {
        int mid = floor((low + high) / 2);
        ms(L, low, mid); //划分子问题
        ms(L, mid + 1, high);
        merge(L, low, mid, high); //合并
    }
}

void MergeSort(std::vector<int> &L)
{
    ms(L, 0, L.size() - 1);
}

int main()
{
    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    MergeSort(L);
    std::cout << "result : ";
    print(L);
}
//Select sort.
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
void SelectSort(vector<int> &L)
{
    int minp = L[0];
    for (int i = 0; i < L.size(); i++)
    {
        int k = i;
        minp = L[i];
        for (int j = i + 1; j < L.size(); j++)
        {
            if (minp > L[j])
            {
                minp = L[j];
                k = j;
            }
        }
        swap(L[k], L[i]);
    }
}
int main()
{
    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    SelectSort(L);
    std::cout << "result : ";
    print(L);
}
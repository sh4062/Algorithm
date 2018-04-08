//Bubble sort.
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
void BubbleSort(vector<int> &L)
{
    bool flag = 0;
    int len = L.size();
    for (int i = 0; i < len; i++)
    {
        flag = 0;
        for (int j = i + 1; j < len; j++)
        {
            if (L[i] > L[j])
            {
                swap(L[i], L[j]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            return;
        }
    }
}
int main()
{
    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    BubbleSort(L);
    std::cout << "result : ";
    print(L);
}
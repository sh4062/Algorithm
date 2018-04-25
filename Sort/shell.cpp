//shell sort
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
void ShellSort(vector<int> &L)
{
    int div = L.size() / 2;
    for (div; div >=1; div /= 2)//缩小增量 
    {
        for (int i = 0; i <=div; i++)//分组
        {
            for (int j = i; j < L.size() - div; j += div)
            {
                for (int k = j; k < L.size(); k += div)
                {
                    if (L[j] > L[k])
                        swap(L[k], L[j]);
                }
            }
        }
    }
}
int main()
{
    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    ShellSort(L);
    std::cout << "result : ";
    print(L);
}
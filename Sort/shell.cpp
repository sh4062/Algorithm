//Shell sort缩小增量排序
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
    int len = L.size();
    if (len <= 0)
        return;
    for (int div = len / 2; div > 0; div = div / 2) //div为增量不断减小
    {
        for (int i = 0; i <= div; ++i) //分组成div组
        {
            for (int j = i; j < len - div; j = j + div)
                for (int k = j; k < len; k = k + div)
                    if (L[j] > L[k])
                        swap(L[j], L[k]);
        }
    }
}
int main()
{
    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4, 999, 1111};
    ShellSort(L);
    std::cout << "result : ";
    print(L);
}


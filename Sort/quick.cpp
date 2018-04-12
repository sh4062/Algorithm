//Quick sort.
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

// int partition(vector<int> &vi, int low, int high)
// {
//     int pivot = vi[high];
//     int i = low - 1;
//     for (int j = low; j < high; j++)
//     {
//         if (vi[j] <= pivot)
//         {
//             i++;
//             swap(vi[i], vi[j]);
//         }
//     }
//     swap(vi[i + 1], vi[high]);
//     return i + 1;
// }
int partition(vector<int> &vi, int low, int high)
{
    int pivot = vi[low];
    int i = low - 1;
    while (low < high)
    {
        while (vi[high] >= pivot && high > low)
            high--;
        if (high > low)
        {
            vi[low] = vi[high];
            low++;
        }
        while (vi[low] < pivot && high > low)
            low++;
        if (high > low)
        {
            vi[high] = vi[low];
            high--;
        }
    }
    vi[low] = pivot;
    return low;
}

void qs(vector<int> &vi, int low, int high)
{
    if (low < high)
    {
        int mid = partition(vi, low, high);
        //Watch out! The mid position is on the place, so we don't need to consider it again.
        //That's why below is mid-1, not mid! Otherwise it will occur overflow error!!!
        qs(vi, low, mid - 1);
        qs(vi, mid + 1, high);
    }
}
void QuickSort(vector<int> &L)
{
    if (L.size() <= 0)
        return;
    qs(L, 0, L.size() - 1);
}
int main()
{
    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    QuickSort(L);
    std::cout << "result : ";
    print(L);
}

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    const int N = 6;                     // 物品个数
    const int V = 10;                    // 背包体积
    int C[N + 1] = { -1,5,6,5,1,19,7 };  // 第 i 个物品的体积（下标从 1 开始）
    int W[N + 1] = { -1,2,3,1,4,6,5 };   // 第 i 个物品的价值
    int F[N + 1][V + 1] = { 0 };         // 状态

    for (int i = 1; i <= N; i++)  // 对于第 i 个物品
        for (int v = 0; v <= V; v++)
        {
            F[i][v] = F[i - 1][v];  //第 i 个不放
            if (v - C[i] >= 0 && F[i][v] < F[i - 1][v - C[i]] + W[i])  // 如果比它大，再放第 i 个
                F[i][v] = F[i - 1][v - C[i]] + W[i];
        }

    cout << "最大价值是：" << F[N][V] << endl;  // 9

    return 0;
}
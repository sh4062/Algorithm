//数据流中的中位数
//解题思路就是用两个堆，一个大顶堆，一个小顶堆来过滤数据。
#include <bits/stdc++.h>
using namespace std;
class Solution
{

    priority_queue<double, vector<double>, less<double>> p;    //从大到小
    priority_queue<double, vector<double>, greater<double>> q; //从小到大

  public:
    void Insert(int num)
    {
        if (p.empty() || num <= p.top())
            p.push(num);
        else
            q.push(num);
        if (p.size() == q.size() + 2)
            q.push(p.top()), p.pop();
        if (q.size() == p.size() + 1)
            p.push(q.top()), q.pop();
    }

    double GetMedian()
    {
        return p.size() == q.size() ? (p.top() + q.top()) / 2 : p.top();
    }
};
#include <bits/stdc++.h>
using namespace std;
void adjustheap(int a[], int n, int k)
{
    int tmp = a[k];
    int i = 2 * k + 1;
    while (i < n)
    {
        if (i + 1 < n && a[i + 1] > a[i])
            i++;
        if (a[i] > tmp)//!tmp
        {
            a[k] = a[i];
            k = i;
            i = 2 * k + 1;
        }
        else
        {
            break;
        }
    }
    a[k] = tmp;
}
void hs(int a[], int n)
{

    for (int i = n / 2; i >= 0; --i)
        adjustheap(a, n, i); //初始堆
    
    for (int i = n - 1; i > 0; --i)//排序
    {
        swap(a[0], a[i]);
        adjustheap(a, i, 0);
    }
}

int main(){
    vector<vector<int>> distribute;
    int n = 0;
    vector<int> data;
    for(int i = 0;i<100;i++)data.push_back(rand()%100);
    for(int i = 0;i<100;i++) cout<<data[i]<<" ";
    int de = 20;
    
    vector<int>data1  ,data2,data3,data4,data5;
    for(int i = 0;i<de;i++)data1.push_back(data[i]);
    for(int i = 20;i<de;i++)data2.push_back(data[i]);
    for(int i = 40;i<de;i++)data3.push_back(data[i]);
    for(int i = 60;i<de;i++)data4.push_back(data[i]);
    for(int i = 80;i<de;i++)data5.push_back(data[i]);

   

}
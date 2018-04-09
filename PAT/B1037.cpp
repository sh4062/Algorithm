
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
long long int m[100005];
struct GSK
{
    int g;
    int s;
    int k;
    GSK(int a, int b, int c) : g(a), s(b), k(c) {}
};
bool cmp(GSK a, GSK b)
{
    if (a.g != b.g)
        return a.g > b.g;
    else if (a.s != b.s)
        return a.s > b.s;
    else
        return a.k > b.k;
}
GSK subGSK(GSK a, GSK b)
{
    GSK res(0, 0, 0);
    if (a.k < b.k)
    {
        res.k = a.k + 29 - b.k;
        a.s--;
    }
    else
    {
        res.k = a.k - b.k;
    }
    if (a.s < b.s)
    {
        res.s = a.s + 17 - b.s;
        a.g--;
    }
    else
    {
        res.s = a.s - b.s;
    }
    res.g = a.g - b.g;
    return res;
}
int main()
{
    int a1, a2, a3, b1, b2, b3;
    int f = 1;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    GSK pp(a1, a2, a3);
    GSK aa(b1, b2, b3);
    if (cmp(pp, aa))
    {
        f = -1;
        swap(pp, aa);
    }
    GSK res(0, 0, 0);
    res = subGSK(aa, pp);
    if (f == -1)
        cout << "-";
    cout << res.g << "." << res.s << "." << res.k;
}
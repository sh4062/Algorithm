#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
const int maxn = 1111;
int main()
{
    double a[1005] = {0}, b[1005] = {0};
    int t1;
    double n1, n2, t2;
    cin >> n1;
    while (n1--)
    {
        cin >> t1 >> t2;
        a[t1] = t2;
    }
    cin >> n2;
    while (n2--)
    {
        cin >> t1 >> t2;
        b[t1] = t2;
    }
    double res[1005] = {0};
    for (int i = 0; i <= 1004; i++)
    {
        res[i] = a[i] + b[i];
    }
    int tt = 1004, count = 0;
    for (tt; tt >= 0; tt--)
    {

        if (res[tt] != 0)
        {
            count++;
        }
    }
    printf("%d", count);
    tt = 1004;
    for (tt; tt >= 0; tt--)
    {

        if (res[tt] != 0)
        {
            printf(" %d %.1f", tt, res[tt]);
        }
    }
}

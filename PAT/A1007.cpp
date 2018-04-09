
#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int t[1000005];
int main()
{
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        if (t[i] >= 0) //!!!等于号很重要啊
            flag = 1;
    }
    if (flag == 0)
    {
        // auto smallest = std::max_element(t,t+n);
        cout << 0 << " ";
        cout << t[0] << " " << t[n - 1];
        // cout <<  "负数";

        return 0;
    }
    int s = 0, maxs = -1, maxi = 0, maxl = 0, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + t[i];
        if (maxs < s)
        {
            maxs = s;
            maxi = i;
            maxl = tmp;
        }

        else if (s < 0)
        {
            s = 0;
            tmp = i + 1;
        }
    }

    //cout<<t[1];

    cout << maxs << " " << t[maxl] << " " << t[maxi];
    //printf("%d %d %d", maxs, t[maxl], t[maxi]);
    return 0;
}
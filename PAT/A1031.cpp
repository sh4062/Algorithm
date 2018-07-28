//1031. Hello World for U (20)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.size();
    int a = len % 3;
    if (a == 0)
    {
        int l = (len - a) / 3;
        int cnt = 0, cnt2 = len - 1;
        for (int i = 0; i < l - 1; i++)
        {
            cout << s[cnt++];
            for (int j = 0; j < l; j++)
            {
                cout << " ";
            }
            cout << s[cnt2--] << '\n';
        }
        for (int i = 0; i < l + 2; i++)
        {
            cout << s[cnt++];
        }
    }
    else if (a == 1)
    {
        int l = (len - a) / 3;
        int cnt = 0, cnt2 = len - 1;
        for (int i = 0; i < l; i++)
        {
            cout << s[cnt++];
            for (int j = 0; j < l - 1; j++)
            {
                cout << " ";
            }
            cout << s[cnt2--] << '\n';
        }
        for (int i = 0; i < l + 1; i++)
        {
            cout << s[cnt++];
        }
    }
    else if (a == 2)
    {
        int l = (len - a) / 3;
        int cnt = 0, cnt2 = len - 1;
        for (int i = 0; i < l; i++)
        {
            cout << s[cnt++];
            for (int j = 0; j < l; j++)
            {
                cout << " ";
            }
            cout << s[cnt2--] << '\n';
        }
        for (int i = 0; i < l + 2; i++)
        {
            cout << s[cnt++];
        }
    }
}
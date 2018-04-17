//1023. Have Fun with Numbers (20)
#include <bits/stdc++.h>
using namespace std;
string s;
int map1[11];
int map2[11];
string dou(string a)
{
    string b;
    int c = 0;
    while (a.size())
    {
        int tmp = int(a[a.size() - 1] - '0') * 2;
        b = to_string(c + tmp % 10) + b;
        if (tmp > 9)
        {
            c = 1;
        }
        else
            c = 0;
        a.erase(a.size() - 1);
    }
    if (c)
        b = '1' + b;
    return b;
}
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        map1[int(s[i] - '0')]++;
    }
    string ds = dou(s);

    if (ds.size() != s.size())
    {
        cout << "No" << '\n';
        cout << ds;
    }
    else
    {
        for (int i = 0; i < ds.size(); i++)
        {
            map2[int(ds[i] - '0')]++;
        }
        for (int i = 0; i < 11; i++)
        {
            if (map1[i] != map2[i])
            {
                cout << "No" << '\n';
                cout << ds;
                return 0;
            }
        }
        cout << "Yes" << '\n';
        cout << ds;
        return 0;
    }
}
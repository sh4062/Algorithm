//1010. Radix (25)
#include <bits/stdc++.h>
using namespace std;
long long int change(char a)
{
    long long r = 0;
    if ('0' <= a && a <= '9')
        r = a - '0' + 0;
    else if ('a' <= a && a <= 'z')
        r = a - 'a' + 10;
    return r;
}
// long long Res(string n, long long radix)
// {
//     long long res = 0;
//     int length = n.size();
//     int index = 0;
//     for (index = 0; index < length; index++)
//     {
//         int oneDigit = change(n[index]);
//         if (oneDigit >= radix)
//             return -2; //一位数字就超过了进制，不合法
//         res = radix * res + oneDigit;
//         if (res < 0)
//             return -1; //溢出
//     }
//     return res;
// }

long long int findlow(string a)
{
    char m = a[0];
    for (long long i = 1; i < a.size(); i++)
    {
        m = max(m, a[i]);
    }
    return change(m);
}
int main()
{
    string a, b;
    long long tag, r;
    cin >> a >> b >> tag >> r;
    long long a1 = 0, b1 = 0;
    long long s = 1, e = 40;
    long long m = 20;
    if (tag == 2)

        swap(a, b);

    long long count = 0;
    while (a.size() != 0)
    {
        a1 += change(a[a.size() - 1]) * pow(r, count);
        count++;
        a.erase(a.end() - 1);
       
    }
    // a1 = Res(a, r);
    s = findlow(b) + 1;

    e = a1+1;//上界为a的值+1

    while (s <= e)
    {

        b1 = 0;
        string tmp = b;
        long long mid = (s + e) / 2;
        // b1 = Res(b, mid);
        count = 0;
        while (tmp.size() != 0)
        {
            b1 += change(tmp[tmp.size() - 1]) * pow(mid, count);
            count++;
            tmp.erase(tmp.end() - 1);
            if (b1 < 0)
            {
                b1 = -1;
                break;
            }
        }

        if (b1 == -1 || b1 > a1)
        {
            e = mid - 1;
        }

        else if (b1 < a1)
        {
            s = mid + 1;
        }

        else if (b1 == a1)
        {
            cout << mid;
            return 0;
        }
    }

    //cout<<change(b[0]);
    cout << "Impossible";
    return 0;
}
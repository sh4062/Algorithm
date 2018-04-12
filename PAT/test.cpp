#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

// long long int Cal(char c)
// {
//     if (c >= '0' && c <= '9')
//     {
//         return (c -'0');
//     }
//     else
//         return (c - 'a' + 10);
// }
long long int Cal(char a)
{
    long long r = 0;
    if ('0' <= a && a <= '9')
        r = a - '0' + 0;
    else if ('a' <= a && a <= 'z')
        r = a - 'a' + 10;
    return r;
}

long long int CalValueBaseRadix(string a, long long int radix)
{

    long long int result = 0;

    long long count = 0;
    while (a.size() != 0)
    {
        result += Cal(a[a.size() - 1]) * pow(radix, count);
        count++;
        a.erase(a.end() - 1);
        if (result < 0)
            return -1;
    }
    return result;
}
long long int findlow(string a)
{
    char m = a[0];
    for (long long i = 1; i < a.size(); i++)
    {
        m = max(m, a[i]);
    }
    return Cal(m);
}

int main(void)
{

    string a, b;
    long long tag;
    long long radixA, radixB;

    cin >> a >> b >> tag >> radixA;
    if (tag == 2)
        swap(a, b);

    long long minRadix, maxRadix;

    //value
    long long i;
    long long int valueA = CalValueBaseRadix(a, radixA);

    minRadix = 0;
    // for (i = 0; i < b.size(); i++)
    // {
    //     if (Cal(b[i]) > minRadix)
    //         minRadix = Cal(b[i]) + 1;
    // }
    minRadix= findlow(b)+1;

    maxRadix = valueA + 1;
    while (minRadix <= maxRadix)
    {
        //cal
        radixB = (minRadix + maxRadix) / 2;
        long long int valueB = CalValueBaseRadix(b, radixB);

        if (valueB == -1 || valueB > valueA)
        {
            maxRadix = radixB - 1;
        }
        else if (valueB < valueA)
        {
            minRadix = radixB + 1;
        }
        else if (valueA == valueB)
        {
            cout << radixB;
            return 0;
        }
    }

    cout << "Impossible";
    return 0;
}
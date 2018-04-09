
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
    {
        return gcd(b, a % b);
    }
}
void prlong(long long a, long long b, long long k, long long f)
{
    if (a == 0 && k == 0)
    {
        cout << 0;
    }
    else
    {
        if (f == 1)
        {
            if (k != 0 && a == 0)
            {
                cout << k;
            }
            else if (k == 0)
            {
                cout << a << "/" << b;
            }
            else
            {
                cout << k << " " << a << "/" << b;
            }
        }
        else
        {
            cout << "(-";
            if (k != 0 && a == 0)
            {
                cout << k;
            }
            else if (k == 0)
            {

                cout << a << "/" << b;
            }
            else
            {
                cout << k << " " << a << "/" << b;
            }
            cout << ")";
        }
    }
}
int main()
{
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    //cout<<a1<<b1<<a2<<b2<<endl;
    long long k1, k2, a3, b3, k3, f1 = 1, f2 = 1, f3 = 1;
    if (a1 < 0)
    {
        f1 = -1;
        a1 = abs(a1);
    }
    if (a2 < 0)
    {
        f2 = -1;
        a2 = abs(a2);
    }
    k1 = a1 / b1;
    k2 = a2 / b2;
    if (k1 != 0)
    {
        a1 = a1 - k1 * b1;
    }
    if (k2 != 0)
    {
        a2 = a2 - k2 * b2;
    }
    long long g1, g2, g3;
    g1 = gcd(a1, b1);
    g2 = gcd(a2, b2);

    a1 = a1 / g1;
    b1 = b1 / g1;
    a2 = a2 / g2;
    b2 = b2 / g2;
    //+
    a3 = f1 * k1 * b1 * b2 + f2 * k2 * b1 * b2 + f1 * a1 * b2 + f2 * a2 * b1;
    b3 = b1 * b2;
    if (a3 < 0)
    {
        f3 = -1;
        a3 = abs(a3);
    }
    k3 = a3 / b3;
    if (k3 != 0)
    {
        a3 = a3 - k3 * b3;
    }
    g3 = gcd(a3, b3);
    a3 = a3 / g3;
    b3 = b3 / g3;
    prlong(a1, b1, k1, f1);
    cout << " + ";
    prlong(a2, b2, k2, f2);
    cout << " = ";
    prlong(a3, b3, k3, f3);
    cout << '\n';
    //-
    a3 = f1 * k1 * b1 * b2 - f2 * k2 * b1 * b2 + f1 * a1 * b2 - f2 * a2 * b1;
    b3 = b1 * b2;
    //cout<<b3;
    f3 = 1;
    if (a3 < 0)
    {
        f3 = -1;
        a3 = abs(a3);
    }
    k3 = a3 / b3;
    if (k3 != 0)
    {
        a3 = a3 - k3 * b3;
    }
    g3 = gcd(a3, b3);
    a3 = a3 / g3;
    b3 = b3 / g3;
    prlong(a1, b1, k1, f1);
    cout << " - ";
    prlong(a2, b2, k2, f2);
    cout << " = ";
    prlong(a3, b3, k3, f3);
    cout << '\n';
    //*
    a3 = (f1 * k1 * b1 + f1 * a1) * (f2 * k2 * b2 + f2 * a2);
    b3 = b1 * b2;
    //cout<<b3;
    f3 = 1;
    if (a3 < 0)
    {
        f3 = -1;
        a3 = abs(a3);
    }
    k3 = a3 / b3;
    if (k3 != 0)
    {
        a3 = a3 - k3 * b3;
    }
    g3 = gcd(a3, b3);
    a3 = a3 / g3;
    b3 = b3 / g3;
    prlong(a1, b1, k1, f1);
    cout << " * ";
    prlong(a2, b2, k2, f2);
    cout << " = ";
    prlong(a3, b3, k3, f3);
    cout << '\n';
    ///
    prlong(a1, b1, k1, f1);
    cout << " / ";
    prlong(a2, b2, k2, f2);
    cout << " = ";
    if (k2 == 0 & a2 == 0)
    {
        cout << "Inf" << '\n';
        return 0;
    }
    a3 = (f1 * k1 * b1 + f1 * a1) * b2;
    b3 = b1 * (f2 * k2 * b2 + f2 * a2);
    //cout<<b3;
    f3 = 1;
    if ((a3 < 0 && b3 > 0) || (a3 > 0 && b3 < 0))
    {
        f3 = -1;
        a3 = abs(a3);
        b3 = abs(b3);
    }
    k3 = a3 / b3;
    if (k3 != 0)
    {
        a3 = a3 - k3 * b3;
    }
    g3 = gcd(a3, b3);
    a3 = a3 / g3;
    b3 = b3 / g3;

    prlong(a3, b3, k3, f3);
    cout << '\n';
}
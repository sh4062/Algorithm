#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
    long int a;
    long int b;
    cin >> a >> b;

    if (a + b < 0)
    {
        cout << "-";
    }
    int c = abs(a + b);
    if (c < 1000)
    {
        cout << c;
        return 0;
    }
    if (c >= 1000&&c<1000000)
    {
        cout << c / 1000;
        cout << ",";
        cout <<setfill('0')<<setw(3)<< c % 1000;
        return 0;
    }
    else{
        cout << c / 1000000;
        cout << ",";
        cout <<setfill('0')<<setw(3)<< (c / 1000)%1000;
        cout << ",";
        cout <<setfill('0')<<setw(3)<< c % 1000;
        return 0;
    }
}

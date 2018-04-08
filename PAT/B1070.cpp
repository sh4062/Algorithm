#include <iostream>
#include <cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N, temp;
    vector<int> in;
    int sum ;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        in.push_back(temp);
    }
    sort(in.begin(), in.end());

    sum = in[0];
    for (int i = 1; i < N; ++i)
        sum = (sum + in[i]) / 2;
    cout << sum;

    system("pause");
    return 0;
}
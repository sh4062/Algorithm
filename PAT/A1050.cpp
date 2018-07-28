/*
 * File: A1050.cpp
 * Project: PAT
 * File Created: Saturday, 28th July 2018 10:23:20 pm
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Saturday, 28th July 2018 10:23:23 pm
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);
    //set<char> TMP;
    for (int i = 0; i < b.size(); i++)
        //    TMP.insert(b[i]);
        a.erase(std::remove(a.begin(), a.end(), b[i]), a.end());
    cout << a;
    return 0;
}

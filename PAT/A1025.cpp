//1025. PAT Ranking (25)
#include <bits/stdc++.h>
using namespace std;

struct PAT
{
    string registration_number;//????说好的13位数 为什么用long long 不行？
    int score;
    int final_rank;
    int location_number;
    int local_rank;
};

bool cmp1(PAT a, PAT b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.registration_number < b.registration_number;
}

vector<PAT> group;
vector<PAT> all;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        group.clear();
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            PAT t;
            cin >> t.registration_number >> t.score;
            t.location_number = i;
            group.push_back(t);
        }
        sort(group.begin(), group.end(), cmp1);
        group[0].local_rank = 1;
        all.push_back(group[0]);
        for (int ii = 1; ii < group.size(); ii++)
        {

            if (group[ii].score == group[ii - 1].score)
            {

                group[ii].local_rank = group[ii - 1].local_rank;
            }
            else
                group[ii].local_rank = ii + 1;
            all.push_back(group[ii]);
        }
        group.clear();
    }

    sort(all.begin(), all.end(), cmp1);
    all[0].final_rank = 1;
    for (int ii = 1; ii < all.size(); ii++)
    {

        if (all[ii].score == all[ii - 1].score)
        {

            all[ii].final_rank = all[ii - 1].final_rank;
        }
        else
            all[ii].final_rank = ii + 1;
    }
    cout << all.size() << '\n';
    for (auto L : all)
    {
        cout << L.registration_number << " " << L.final_rank << " " << L.location_number << " " << L.local_rank << '\n';
    }
}
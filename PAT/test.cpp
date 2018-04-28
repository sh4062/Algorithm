#include <iostream>  
#include <vector>  
#include <string>  
#include <algorithm>  
  
using namespace std;  
  
struct Testee  
{  
    string id;  
    int score;  
    int location_num;  
    int loca_rank;  
    int final_rank;  
};  
  
vector<Testee> testee_final;  
vector<Testee> testee_local;  
  
bool cmp( Testee a,  Testee b)  
{  
    if (a.score != b.score)  
        return a.score > b.score;  
    else  
        return a.id < b.id;  
}  
  
int main()  
{  
    int n;  
    cin >> n;  
    int tot = 0;  
    for (int i = 0; i < n; i++)  
    {  
        int k;  
        cin >> k;  
        tot += k;  
        Testee tmp;  
        testee_local.clear();  
        for (int j = 0; j < k; j++)  
        {  
            cin >> tmp.id >> tmp.score;  
            tmp.location_num = i;  
            testee_local.push_back(tmp);  
        }  
        sort(testee_local.begin(), testee_local.end(), cmp);  
        testee_local[0].loca_rank = 0;  
        for (int i = 1; i < k ; i++)  
        {  
            if (testee_local[i ].score == testee_local[i-1].score)  
                testee_local[i ].loca_rank = testee_local[i-1].loca_rank;  
            else  
                testee_local[i ].loca_rank = i ;  
        }  
        for (int j = 0; j < k; j++)  
        {  
            tmp = testee_local[j];  
            testee_final.push_back(tmp);  
        }  
    }  
    sort(testee_final.begin(), testee_final.end(), cmp);  
    testee_final[0].final_rank = 0;  
    for (int i = 1; i < tot; i++)  
    {  
        if (testee_final[i ].score == testee_final[i-1].score)  
            testee_final[i].final_rank = testee_final[i-1].final_rank;  
        else  
            testee_final[i ].final_rank = i ;  
    }  
    cout << testee_final.size() << endl;  
    for (int i = 0; i < testee_final.size(); i++)  
    {  
        cout << testee_final[i].id << " " << testee_final[i].final_rank + 1 << " " << testee_final[i].location_num + 1 << " " << testee_final[i].loca_rank + 1 << endl;  
    }  
    return 0;  
}  
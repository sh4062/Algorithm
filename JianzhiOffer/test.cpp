#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

bool VerifySquenceOfBST(vector<int> sequence)
{
    if (sequence.empty())
        return false;
    vector<int> l;
    vector<int> r;
    int i = 0;
    int len = sequence.size();
    for (i; sequence[i] < sequence[len - 1];)
    {

        ++i;
    }
    for (int j = i; j < len - 1; ++j)
    {
        if (sequence[j] < sequence[len - 1])    
            return false;
    }
    if (i)
    {
        for (int m = 0; m < i; ++m)
            l.push_back(sequence[m]);
    }
    if (i != len - 2)
    {
        for (int m = i; m < len - 1; ++m)
            r.push_back(sequence[m]);
    }
    bool left = true, right = true; // 看左右子树是否是二叉搜索树
    if (l.size() > 1)
        VerifySquenceOfBST(l);
    if (l.size() > 1)
        VerifySquenceOfBST(r);

    return (left && right);
}
int GetNumberOfK(vector<int> data ,int k) {
     vector<int>::iterator result;
     vector<int>::iterator result2;
         result=lower_bound(data.begin(),data.end(),k);
         result2=upper_bound(data.begin(),data.end(),k);
        return int(result2-result);

    }
int main()
{
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    t.push_back(3);
    t.push_back(3);
    t.push_back(3);
    t.push_back(2);
    

    cout << GetNumberOfK(t,3);
}
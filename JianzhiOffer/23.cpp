class Solution {
public:
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
        for (int m = 0; m < i; ++m)l.push_back(sequence[m]);
    }
    if (i!=len-2){
        for (int m = i; m < len-1; ++m)r.push_back(sequence[m]);
    }
    bool left = true, right = true; // 看左右子树是否是二叉搜索树
    if (l.size() > 1)
        VerifySquenceOfBST(l);
    if (l.size() > 1)
        VerifySquenceOfBST(r);

    return (left && right);
}
};
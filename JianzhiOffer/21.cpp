class Solution
{
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> tmp;
        if (pushV.size() == 0 || popV.size() == 0 || popV.size() != pushV.size())
            return false;
        for (int i = 0, j = 0; i < pushV.size();)
        {
            tmp.push(pushV[i++]);
            while (j < popV.size() && tmp.top() == popV[j])
            {
                tmp.pop();
                j++;
            }
        }
        return tmp.empty();
    }
};
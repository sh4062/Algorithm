//和为S的两个数字

class Solution
{
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        unordered_map<int, int> m;
        int a = -1, b = -1;
        int res = INT_MAX;
        vector<int> r;
        for (int i = 0; i < array.size(); i++)
        {
            if (m.find(sum - array[i]) != m.end())
            {
                if (res != min(res, array[i] * (sum - array[i])))
                {
                    res = min(res, array[i] * (sum - array[i]));
                    a = array[i];
                    b = sum - array[i];
                }
            }
            else
                m[array[i]] = i;
        }
        if (a == -1 && b == -1)
            return r;
        r.push_back(b);
        r.push_back(a);

        return r;
    }
};
//连续子数组的最大和
class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int sum = array[0];
        int res = array[0];
        for (int i = 0; i < array.size(); i++)//全为负数
        {
            if (array[i] > 0)
                break;
            res = max(res, array[i]);
            if (array[i] < 0 && i == array.size() - 1)
                return res;
        }
        for (int i = 1; i < array.size(); i++)
        {
            sum = sum + array[i];
            res = max(sum, res);

            if (sum < 0)
                sum = 0;
        }
        return res;
    }
};
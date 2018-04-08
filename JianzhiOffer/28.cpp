//数组中出现次数超过一半的数字
class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int n = numbers.size();
                 //map 记录出现次数
        unordered_map<int, int> m;
                int count;
                for (int i = 0; i < n; i++)
        {
                        count = ++m[numbers[i]];
                        if (count > n / 2) return numbers[i];
                    
        }
                return 0;
    }
};

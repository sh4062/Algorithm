//丑数
/*从1开始123456
之后1 2 3 5
4 = 2*2 6 =3*2

*/


class Solution
{
  public:
    int GetUglyNumber_Solution(int index)
    {
        if (index < 7)
            return index;

        vector<int> k(index);
        k[0] = 1;
                int t2 = 0, t3 = 0, t5 = 0;
                for (int i = 1; i < index; i++)
        {
                        k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
                        if (k[i] == k[t2] * 2) t2++;
                        if (k[i] == k[t3] * 3) t3++;
                        if (k[i] == k[t5] * 5) t5++;
                    
        }
                return k[index - 1];
    }
};
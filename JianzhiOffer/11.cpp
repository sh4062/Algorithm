class Solution
{
  public:
    int NumberOf1(int n)
    {
        int cnt = 0;
        if (n < 0)
        {
            n = n & 0x7FFFFFFF;
            cnt++;
        }
        while (n)
        {
            cnt += n & 1;
            n = n >> 1;
        }
        return cnt;
    }
};//朴素的统计办法是：先判断n的奇偶性，为奇数时计数器增加1，然后将n右移一位，重复上面步骤，直到移位完毕。a&b 的操作的结果：a、b中对应位同时为1，则对应结果位也为1、


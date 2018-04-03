//题目描述
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
class Solution
{
  public:
    double Power(double a, int b)
    {
        double s = 1;
        if (b == 0)
            return 1;
        if (b < 0)
        {
            a = 1 / a;
            b = -b;
        }
        while (b > 0)
        {
            if (b % 2 == 1)
            { //b=b>>1保证了在最后一步肯定会执行该if判断
                s = s * a;
            }
            a = a * a;
            b = b >> 1;
        }
        return s;
    }
};
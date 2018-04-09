/*对vector容器内的数据进行排序，按照 将a和b转为string后
 若 a＋b<b+a  a排在在前 的规则排序,
 如 2 21 因为 212 < 221 所以 排序后为 21 2 
  to_string() 可以将int 转化为string

reference to non-static member function must be called
问题的原因其实就是函数参数不匹配的问题。因为我们普通的成员函数都有一个隐含的this指针，
表面上看我们的谓词函数com（）只有两个参数，但实际上它有三个参数，而我们调用sort（）排序函数的时候只需要用到两个参数进行比较，
所以就出现了形参与实参不匹配的情况（函数有三个形参，但是只输入了两个实参）。
*/
class Solution
{
  public:
    static bool cmp(int a, int b)
    {
        string A, B;
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A > B;
    }
    string PrintMinNumber(vector<int> numbers)
    {
        string res = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for (int i = 0; i < numbers.size(); i++)
        {
            res = to_string(numbers[i]) + res;
        }
        return res;
    }
};
//包含min函数的栈
class Solution
{
  public:
    void push(int value)
    {
        stk.push(value);
        if (stk_min.size() == 0 || value < stk_min.top())
            stk_min.push(value);
        else
            stk_min.push(stk_min.top());
    }
    void pop()
    {
        stk_min.pop();
        stk.pop();
    }
    int top()
    {
        return stk.top();
    }
    int min()
    {
        return stk_min.top();
    }

  private:
    stack<int> stk;
    stack<int> stk_min;
};

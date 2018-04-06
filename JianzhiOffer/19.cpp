//顺时针打印矩阵
class Solution
{
  public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> result;
        if (row == 0 || col == 0)
            return result;
        int left = 0, right = col - 1, top = 0, btm = row - 1;
        while (left <= right && top <= btm)
        {
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            if (top < btm)
                for (int i = top + 1; i <= btm; i++)
                    result.push_back(matrix[i][right]);
            if (top < btm && left < right)
                for (int i = right - 1; i >= left; i--)
                    result.push_back(matrix[btm][i]);
            if (top + 1 < btm && left < right)
                for (int i = btm - 1; i >= top + 1; i--)
                    result.push_back(matrix[i][left]);
            left++;
            right--;
            top++;
            btm--;
        }
        return result;
    }
};
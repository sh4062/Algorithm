class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size(),col = array[0].size();
        int i,j;
        for(i=row-1, j=0; i>=0 && j<col;){
            if(array[i][j]==target)
                return true;
            if(array[i][j]>target)
            {
                i--;
                continue;
            }
            if(array[i][j]<target)
            {
                j++;
                continue;
            }
        }
        return false;
    }
};
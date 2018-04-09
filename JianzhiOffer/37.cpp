//数字在排序数组中出现的次数
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
     vector<int>::iterator result;
     vector<int>::iterator result2;
         result=lower_bound(data.begin(),data.end(),k);
         result2=upper_bound(data.begin(),data.end(),k);
        return int(result2-result);

    }
};
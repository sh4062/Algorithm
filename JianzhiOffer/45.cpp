class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5)return false;
        int min = 14,max=-1,flag = 0;
        for(int i = 0;i<numbers.size();i++){
            int t = numbers[i];
            if(t<0||t>13)return false;
            if(t==0) continue;
            if(((flag >> t) & 1) == 1) return false;
            flag |= (1 << t);
            if(t > max) max = t;
            if(t < min) min = t;
            if(max - min >= 5) return false;
        }
        return true;
        
        
    }
};
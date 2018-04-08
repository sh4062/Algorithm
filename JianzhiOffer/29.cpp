//最小的K个数
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size()==0||k>input.size()||k<=0)return res;
        int s = 0,e = input.size()-1;
        int index = Partition(input,s,e);
        while(index!=k-1){
            if(index >k-1){
                e = index - 1;
                index = Partition(input,s,e);
            }
            else{
                s = index + 1;
                index = Partition(input,s,e);
            }
        }
        for(int i = 0;i<k;i++){
            res.push_back(input[i]);
        }
        return res;
        
    }
    int Partition(vector<int>& input, int begin, int end)
    {
        int low=begin;
        int high=end;
         
        int pivot=input[low];
        while(low<high)
        {
            while(low<high&&pivot<=input[high])
                high--;
            input[low]=input[high];
            while(low<high&&pivot>=input[low])
                low++;
            input[high]=input[low];
        }
        input[low]=pivot;
        return low;
    }
};
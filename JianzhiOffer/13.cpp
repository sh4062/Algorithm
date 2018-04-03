class Solution {
public:
    void reOrderArray(vector<int> &a) {
        vector<int> res;
        for(int i = 0;i<a.size();i++){
            if(a[i]&1!=0)
            res.push_back(a[i]);
            
        }
        for(int i = 0;i<a.size();i++){
            if((a[i]&1)==0)
            res.push_back(a[i]);
            
        }
        a = res;
        
        
        
    }
};
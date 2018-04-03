class Solution {
public:
    int jumpFloorII(int target) {
        if (target == 1 || target == 0)   
        {  
            return 1;  
        }   
        else  
        {  
            return 2 * jumpFloorII(target - 1);  
        }  
    }  

    
};
//F(n)= F(n-1)+...F(0)
//F(n-1)=F(n-2)+...F(0)
//F(n)= 2*F(n-1)
class Solution {
public:

     int rectCover(int target) {
         int fibn = 0,fib1 = 0,fib2 = 1;
        if( target == 0) return 0;
        if (target == 1 )   
        {  
            return 1;  
        }   
        else  
        {  
            for(int i = 0;i<target;i++){
                fibn = fib1 + fib2;
                fib1 = fib2;
                fib2 = fibn;
            }
            return fibn;
        }  
    }  
};
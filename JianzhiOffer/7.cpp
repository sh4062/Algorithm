class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0,1};  
    if(n < 2)  
        return result[n];  
    int fibOne = 0;
    int fibTwo = 1;
    int fibN = 0;
    for(int i = 2;i<=n;i++){
        fibN = fibOne + fibTwo;
        fibOne = fibTwo;
        fibTwo = fibN;
    }
    return fibN;
        
    }
};
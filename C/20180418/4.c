//4. 统计一个整数对应的二进制数的1的个数。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//按位与呗
int countOne(int num)  
{  
    int count = 0;  
    while ( num )  
    {  
        if( num & 1 ){  
            ++count;  
        }  
        num >>= 1;  
    }  
    return count;  
}  
int main(){

}
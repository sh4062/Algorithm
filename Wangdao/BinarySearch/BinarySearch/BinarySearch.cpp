#include <iostream>  
#include<cmath>
using namespace std;
 int count = 0;
int binarySearch(const int A[], int X, int N){  
    int start = 0, end = 0, mid;  
    end = N;  
    while (start <= end) {  
        mid = floor(double(start + end)/2+0.5);  
        if (X > A[mid]) {  
            start = mid+1;  
			count++;
            continue;  
        }else if (X < A[mid]){  
            end = mid-1;  
			count++;
            continue;  
        }else{  
			count++;
            return mid;  
        }  
    }  
    return -1;  
}  
  
int main()  
{  
    int A[]={18,53,54,74,99};  
    int N = sizeof(A)/sizeof(int);  
    int X = 53;  
      
    int locate = binarySearch(A, X, N);  
    if (locate == -1) {  
        printf("Can't find the element %d\n",X);  
    }else{  
        printf("The element %d is locate in %d\n",X,locate);  
		printf("BS times is %d\n",count);  
    }  
      
    return 0;  
}  
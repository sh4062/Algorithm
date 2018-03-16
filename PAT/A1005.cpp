#include <iostream>  
#include <cstdio>  
#include <cstring>  
char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};  
  
int main(int argc, const char * argv[]) {  
    char n[110];  
    scanf("%s", n);  
    int sum = 0;  
    int len = strlen(n);  
    for(int i =0; i < len; i++) {  
        sum += n[i] - '0';  
    }  
    int a[10];  
    int k = 0;  
    if(sum == 0) printf("zero\n");  
    while(sum > 0){  
        a[k] = sum % 10;  
        sum /= 10;  
        k++;  
    }  
    for(int i = k - 1; i >=0; i--){  
        printf("%s", num[a[i]]);  
        if(i > 0) printf(" ");  
    }  
    return 0;  
}  
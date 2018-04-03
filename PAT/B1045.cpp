#include <iostream>  
#include <algorithm>  
#include <stdio.h>  
using namespace std;  
const int N = 1005;  
 int main()  {
//freopen("input.txt", "r", stdin); 
   //freopen("output.txt", "w", stdout);
   int n;
   scanf("%d",&n);  
   int num[N],num_s[N];  //一个原始数据，另一个保存已经排好的数据  
   for(int i=0;i<n;i++)  
   {  
       scanf("%d",&num[i]);  
       num_s[i]=num[i];  
   }  
   sort(num_s,num_s+n);  
   int count=0,max=0;  
   int res[N];  
     
   for(int i=0;i<n;i++)  
   {  
       if(num[i]>max)  
            max=num[i];  
        if(max==num[i] && num[i]==num_s[i])  //如果当前数是从第一个数到当前数最大的一个，且与排完顺序对应位置的数相同则该数就有可能是主元!!!
            res[count++]=num[i];  
   }  
    printf("%d\n",count);  
    //sort(res,res+count);  
    for(int i=0;i<count;i++)  
        if(i==0)  
             printf("%d",res[i]);  
        else  
            printf(" %d",res[i]);  
    printf("\n");  
	//fclose (stdin);
	//fclose (stdout);
    return 0;  
}  
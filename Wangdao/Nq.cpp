
/*  Function : n-皇后问题的回溯算法  
 *  Author   : wyh7280  
 *  Time     : 2015.05.20   10:36:00.000 
 *  Note     : 输出n-皇后的所有可行解,输出列号(0~n-1)  
 */  
#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
#include <cmath>  
#include <cstring>  
using std::cin;  
using std::cout;  
using std::endl;      
int n;                //皇后个数   
bool place(int k, int i, int *x);  
void nQueens(int k, int n, int *x);  
int count;
int main()  
{  
    cout << "请输入n-皇后中n的值:";  
    while(cin >> n)  
    {  
       int *x = new int [n + 1];  
       cout << "输出可行解:" <<endl;   
       if(n == 2 || n==3)  
       cout << "0" <<endl;   
       nQueens(0, n, x);   
       cout << "请输入n-皇后中n的值:";  
    }  
    return 0;  
}  
  
bool place(int k, int i, int *x)  
{  //判定两个皇后是否在同一列或者在同一斜线上   
   for(int j = 0; j < k; j++)  
      if((x[j] == i) || abs(x[j] - i) == abs(j - k))  return false;  
    return true;  
}  
  
void nQueens(int k, int n, int *x)  
{  
    for(int i = 0; i < n; i++)  
    {  
        if(place(k, i, x))  
        {  
           x[k] = i;  
           if(k == n - 1)  
           {  
              for(i = 0; i < n; i++)  cout << x[i] << " ";  
              cout << endl;  
           }      
           else  
              nQueens(k+1, n, x);  
        }   
    }   
}  
#include<iostream>
#include <algorithm>    
using namespace std;
bool compare(int a,int b)
{
  return a>b; //升序排列，如果改为return a>b，则为降序
}
int main(){
  int a[10000] = {0};
  int save[101] = {0};
  int n = 0,m = 0,sub = 0;
  cin>>n;
  for ( int i = 0; i < n; i++ ) { 
        cin>>m;
        if ( a[m] == 2 ) {    //如果已经被覆盖,则无需循环   
            continue;  
        }  
        a[m] = 1;  
        while ( m != 1 ) {  //循环遍历过的数字作为数组下标对应的数组元素设为2   
            if (m % 2) {  
                a[m = (3 * m + 1) / 2] = 2;  
            }   
            else {  
                a[m /= 2] = 2;  
            }  
        }
        
    }
    for(int i = 1; i < 102; i++) {   //数组值为1的下标储存并排序   
        if(a[i] == 1) {  
            save[sub++] = i;  
        }  
    }  
    sort(save, save + sub, compare);
      
    for(int i = 0; i < sub; i++ ) {  
        cout<<(save[i]);  
        if(i != sub - 1) {  
            cout<<(" ");  
        }  
    }  
    return 0;  
    
  
}
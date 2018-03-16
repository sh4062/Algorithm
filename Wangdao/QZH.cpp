#include<iostream>
//pre post order 
#include<cstdio>
#include<cstring>
using namespace std;
char pre_order_arry[30];
char in_order_arry[30];
char post_order_arry[30];

void PrintPostOrder(int pos1, int pos2, int n)
{
    if (n == 1)
    {
        cout << pre_order_arry[pos1];
        return;
    }
    if (n == 0)
        return;
  
    int i = 0;
    for (; pre_order_arry[pos1] != in_order_arry[pos2 + i]; i++)
        ;
  
    PrintPostOrder(pos1 + 1, pos2, i);
    PrintPostOrder(pos1 + i + 1, pos2 + i + 1, n - i - 1);
    cout << pre_order_arry[pos1];
}

void PrintPreOrder(int pos1, int pos2, int n)
{
    if (n == 1)
    {
        cout << post_order_arry[pos1+n-1];
        return;
    }
    if (n == 0)
        return;
  
    int i = 0;
    for (; post_order_arry[pos1+n-1] != in_order_arry[pos2 + i]; i++)
        ;
        
    //cout<<i;

    cout << post_order_arry[pos1+n-1];
     PrintPreOrder(pos1, pos2, i);
     //cout << pos1 + i<<pos2 + i+1<<n - i - 1;
     PrintPreOrder(pos1 + i, pos2 + i+1, n - i - 1);
    
}
int main(){
    // while(scanf("%s",pre_order_arry) != EOF){
    //     scanf("%s",in_order_arry);
    //     int l1 = strlen(pre_order_arry);
    //     int l2 = strlen(in_order_arry);
    //     PrintPostOrder(0,0,l1);
    //     printf("\n");
    //     break;
    // }
        while(scanf("%s",post_order_arry) != EOF){
        scanf("%s",in_order_arry);
        int l1 = strlen(post_order_arry);
        int l2 = strlen(in_order_arry);
        PrintPreOrder(0,0,l1);
        printf("\n");
        break;
    }
    return 0;
}
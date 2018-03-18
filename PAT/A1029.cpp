// #include<iostream> //set内存超
// #include<iomanip>
// #include<set>
// #include<vector>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     set<int> iset;
//     int n1,n2;
//     double t ,res = 0;
//     cin>>n1;
//     for(int i = 1;i<=n1;i++){
//         cin>>t;
//         iset.insert(t);
//     }
//     cin>>n2;
//     for(int i = 1;i<=n2;i++){
//         cin>>t;
//         iset.insert(t);
//     }
//     set<int>::iterator it1= iset.begin(),it2;

//     // vector<int> v; 
        
//         int count =0;
//         for(it1 ;it1!=iset.end();it1++){
//             count++;
//             if(count == (iset.size()-1)/2+1)break;}
//         cout<<*it1;
//     // if(v.size()%2!=0)cout<<v[v.size()/2];
//     // else cout<<(v[v.size()/2]+v[v.size()/2-1])/2;
// }
#include<iostream>  
#include<algorithm>  
using namespace std;  
int main()  
{  
    int n, m,i=0;  
    int arr[2000000] = {0};  
    scanf("%d", &n);  
    while (getchar()!= '\n')//输入回车时结束一行输入，换行  
    {  
        scanf("%d", &arr[i]);  
        i++;  
    }  
    scanf("%d", &m);  
    while (getchar() != '\n')  
    {  
        scanf("%d", &arr[i]);  
        i++;  
    }  
    sort(arr, arr + n + m); //排序  
    printf("%d", arr[(n + m - 1) / 2]);//求中位数  
    return 0;  
}  
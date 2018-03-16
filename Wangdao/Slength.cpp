#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int lena, lenb;
char a[1010], b[1010];
void read() {
    //scanf("%s%s", a, b);
	cin.getline(a,1010);
	cin.getline(b,1010);
    lena = strlen(a);
    lenb = strlen(b);
}

int dp[1010][1010];
void work() {
    for(int i=1; i<=lena; i++) dp[i][0] = i;
    for(int j=1; j<=lenb; j++) dp[0][j] = j;
    for(int i=1; i<=lena; i++)
        for(int j=1; j<=lenb; j++)
            if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
    printf("%d\n", dp[lena][lenb]);
}

int main() {
    read();
    work();
    return 0;
}
// int poww(int a,int b){
//     int ans=1,base=a;
//     while(b!=0){
//         if(b&1!=0)
//         ¡¡¡¡ans*=base;
//         base*=base;
//         b>>=1;
// ¡¡ }
//     return ans;
// }
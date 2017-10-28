#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
typedef long long LL;  

  
const int N = 1000000;  
char s[N];  
int nex[N];  
void getnext(){  
    int len = strlen(s);  
    int k = -1;  
    nex[0] = -1;  
    for(int i = 1; i < len; i++){  
        while(k!=-1 && s[k+1]!=s[i])  
            k = nex[k];  
        if(s[k+1]==s[i])  
            k++;  
        nex[i] = k;  
    }  
}  
int mp[N];  
int main(){  
    int T,ll;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&ll);
    scanf("%s",s);  
    getnext();  
    int len = strlen(s);  
    memset(mp,0,sizeof(mp));  
    for(int i = len; i >= 1; i--){  
        mp[i]++;  
        mp[nex[i-1]+1] += mp[i];  
//        printf("%d %d \n",i,mp[i]);  
    }  
    LL out = 0;  
    for(int i = 1; i <= len; i++){  
        out = out+(LL)i*(LL)mp[i];  
    }  
    printf("%lld\n",out);  
    return 0;  }
}  

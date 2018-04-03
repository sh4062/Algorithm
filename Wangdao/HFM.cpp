#include <stdio.h>
#include <queue>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        priority_queue <int,vector<int>,greater<int> > Q;
        int m;
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            Q.push(m);
        }
        int a,b;
        int ans=0;
        while(Q.size()>1){
        a=Q.top();
        Q.pop();
        b=Q.top();
        Q.pop();
            ans+=a+b;
        Q.push(a+b);
        }
    //    int c=Q.top();
    //    Q.pop();
        printf("%d\n",ans);
    }
    return 0;
}

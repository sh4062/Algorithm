#include<cstdio>
const int N =1111;
int Tree[N];
// int findRoot(int x){
//     if(Tree[x] == -1) return x;//若当前节点为根则返回
//     else return findRoot(Tree[x]);//递归查找
// }
int findRoot(int x){
    if(Tree[x] == -1) return x;//若当前节点为根则返回
    else {int tmp = findRoot(Tree[x]);
    Tree[x]  = tmp;//将当前节点的双亲节点设置为查找返回的根节点
    return tmp;}
}

int main(){
    int n, m;
    while(scanf("%d", &n)!= EOF && n != 0){
        scanf("%d", &m);
        for(int i = 1;i <=n;i++) Tree[i] = -1;
        while(m-- !=0){
            int a , b;
            scanf("%d%d",&a,&b);
            a = findRoot(a);
            b = findRoot(b);
            if(a!=b) Tree[a]=b;}//Union
            int ans =0;
            for(int i = 1; i<=n;i++){
                if(Tree[i] == -1) ans++;}
                printf("%d \n",ans-1);


            
        }
    
}
//4 2 1 3 4 3 3 3 1 2 1 3 2 3 5 2 1 2 3 5 999 0 0(INPUT)1 0 2 998(OUTPUT)
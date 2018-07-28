#include<stdio.h>

#define MAX_N 1000100

struct Node{
    char data;
    int next;
    bool flag;
}node[MAX_N];

void init(){
    for(int i=0;i<MAX_N;i++){
        node[i].flag=false;
    }
}

int main(){
    init();
    int n;
    int l1,l2;
    int address,next;
    char data;
    int p;
    scanf("%d%d%d",&l1,&l2,&n);

    for(int i=0;i<n;i++){
        scanf("%d %c %d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
    }
    for(int i=l1;i!=-1;i=node[i].next){
        node[i].flag=true;
    }
    for(p=l2;p!=-1;p=node[p].next){
        if(node[p].flag)
            break;
    }
    if(p!=-1)
        printf("%05d",p);
    else
        printf("-1");
}
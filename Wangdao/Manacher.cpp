#include<iostream>  
#include<string.h>
#include<cstdio>
#include<algorithm>  
using namespace std;

char s[1000];
char s_new[2000];
int p[2000];//p[i]是以i为中心的最长回文半径

int Init(){
    int i = 0,j = 2;
    s_new[0] = '$';
    s_new[1] = '#';
    for(i;i<strlen(s);i++){
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';
    return j;


}

int manacher(){
    int len = Init();
    int id=0,mx=0,i=0,res = 0;
    for (int i = 1; i < len; i++)
    {
    if(0 < mx - i)p[i] = min(p[2*id-i],mx-i);
    else p[i] = 1;
    while(s_new[i+p[i]] ==s_new[i-p[i]])p[i]++;
    if(mx < 1+p[i]){
        id = i;
        mx = 1+p[i];


    }
    res = max(res,p[i]-1);
    }
    return res;

}
int main()
{
    while (printf("请输入字符串：\n"))
    {
        scanf("%s", s);
        printf("最长回文长度为 %d\n\n", manacher());
    }
    return 0;
}


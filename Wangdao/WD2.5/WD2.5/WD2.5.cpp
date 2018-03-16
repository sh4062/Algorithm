// WD2.5.cpp : 定义控制台应用程序的入口点。
//Hash

#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF && n!=0){
		int Hash[101] = {0};
		for(int i = 1;i <= n;i++){
		int x;
		scanf("%d",&x);
		Hash[x]++;}
	    int x;
	    scanf("%d",&x);
	    printf("%d\n",Hash[x]);}

	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

char pat[10005];
char word[1000005];
int anext[10005];
int lp, lw;




int main()
{
	int c;
	int t, ti;
        int x,y;

	cin>>t;
           while(t--){
			memset(pat, 0, 10005 * sizeof(char));
			memset(word, 0, 1000005 * sizeof(char));
			scanf("%d", &lw);
			scanf("%s", word);
			scanf("%d", &lp);
			scanf("%s", pat);
			
			
			//lp = 0;
			//while(pat[lp]){
				//++lp;

			//}
			//lw = 0;
			//while(word[lw]){
			//	++lw;
			//}

			int i = 0;
	int j = -1;

	memset(anext, 0, 10005 * sizeof(int));
	anext[0] = -1;
	while(i <= lp - 1){
		if(j == -1 || pat[i] == pat[j]){
			++i;
			++j;
			anext[i] = j;
		}else{
			j = anext[j];
		}
	}
				int index;
	int pos;
	int count;

	count = index = pos = 0;
	while(index <= lw - 1){
		if(pos == -1 || word[index] == pat[pos]){
			++index;
			++pos;
 
		}else{
			pos = anext[pos];
		}

		if(pos == lp){
			++count;
                        
		}
	}
			printf("%d\n", count);
		}
	

	return 0;
}

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

void get_next()
{  
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
}

void count_kmp()
{
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
                         char *p=word;
                 for(int m=1;m<=lp;m++){
                           p[index-m]='0';}
                
                        
		}
	}

	
}
void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

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
			
			

                        while(strstr(word,pat)){
			get_next();
			count_kmp();
                        char *p=word;
                          removeChar(p,'0');}
			printf("%s\n", word);
                         
		}
	

	return 0;
}

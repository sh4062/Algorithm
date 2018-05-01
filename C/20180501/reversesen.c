#include<string.h>
#include<stdio.h>
void reverse(char *p, char *q){  
    while(p < q){  
        char tmp = *p;  
        *p++ = *q;  
        *q-- = tmp;  
    }  
}  
  
char* reverseSentence(char *s){  
    char *p = s; //指向单词的首字符  
    char *q = s; //指向空格或者'\0'  
    while(*q){  
        if(*q == ' '){  
            reverse(p, q-1);  
            q++;  
            p = q;  
        }  
        else  
            q++;  
    }  
    reverse(p, q-1);  
    reverse(s, q-1);  
    return s;  
}  

int main(){
    char a[20]="I am a student";
    reverseSentence(a);
    printf("%s",a);
}
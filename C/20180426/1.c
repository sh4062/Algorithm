#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
//将《The_Holy_Bible.txt》中的标点符号替换成空格, 大写字母转换成小写字母并将处理
//过的文本保存到 “The_Holy_Bible_Res.txt”中。
int main(){
    FILE *fp=fopen("./20180426/1","r");
    if(fp==NULL)perror("");
    FILE *fp1=fopen("./20180426/2","w+");
    // fprintf(fp,"asdasdasdas%d",99999999);
    // int aa=fputc('A',fp);
    // fseek(fp,0,SEEK_END);
    // int ret =fputc('7',fp);
    char c ,p;
    // int a =fgetc(fp);
     while((c=fgetc(fp))!=EOF){
        fputc(c,fp1);
        if(ispunct(c)!=0){
            fseek(fp1,-1,SEEK_CUR);
          fputc(' ',fp1);
        }
           if(isalpha(c)!=0){
            fseek(fp1,-1,SEEK_CUR);
          fputc(tolower(c),fp1);
        }
     }
    fclose(fp);
    fclose(fp1);
}
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp=fopen("./20180426/file.txt","w+");
    if(fp==NULL)perror("");
    // fprintf(fp,"asdasdasdas%d",99999999);
    int aa=fputc('A',fp);
    // fseek(fp,0,SEEK_END);
    // int ret =fputc('7',fp);
    char c ;
    int a =fgetc(fp);
     while((c=fgetc(fp))!=EOF){
         printf("1");
     }
    fclose(fp);
}
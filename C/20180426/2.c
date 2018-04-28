//统计” The_Holy_Bible_Res.txt “ 中字符的个数,行数,单词的个数,统计单词的词频并打
//印输出词频最高的前 10 个单词及其词频。
//naive realize
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct tmp
{
    int num;
    char a[20];
} tmp;
int cmp(const void*p1,const void*p2){
    return (*(tmp *)p1).num < (*(tmp *)p2).num?1:-1;
}
int main()
{
    FILE *fp = fopen("./20180426/2", "r");
    if (fp == NULL)
        perror("");
    int cntchar = 0, cntrow = 0, cntstring = 0;
    char c, p;
    // int a =fgetc(fp);

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
        {
            cntrow++;
        }
        if (isspace(c) == 0)
        {
            cntchar++;
        }
    }
    fclose(fp);
    FILE *fp1 = fopen("./20180426/2", "r");
    if (fp1 == NULL)
        perror("");

    tmp *res = (tmp *)calloc(99999999, sizeof(tmp ));
    char buf[20] = {0};
    int i = 0;
    while (!feof(fp1))
    {
        memset(buf, 0, sizeof(buf)); //清空缓冲区
        fscanf(fp1, "%s", buf);      //从文件中读取一段数据存入缓冲区（fscanf遇到空格或回车就结束，它会把空格或回车转换为\0，所以它是读一小段数据）
        
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (strcmp(buf , res[j].a)==0)
            {
                res[j].num++;
                flag=1;
                break;
            }
        }
        if(flag == 1){flag = 0;continue;}
        strcpy(res[i].a, buf);
        res[i].num++;
        i++;
        cntstring++;
    }
    qsort(res,i,sizeof(tmp),cmp);
    fclose(fp1);
    printf("%d %d %d\n", cntchar, cntrow + 1, cntstring);
    for(int m =0;m<10;m++){
        printf(" %s ",res[m].a);
        printf(" %d ",res[m].num);
    }
    printf("\n------------------------Answers------------------------------\n");
    printf("'the': 64045, 'and': 51714, 'of': 34765, 'to': 13643, 'that': 12916, 'in': 12674, 'he': 10431, 'shall': 9837, 'unto': 9003, 'for': 8985, 'i': 8853.");
}
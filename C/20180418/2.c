#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Stat(char *str, int count[])
{
    int i;
    for (i = 0; i < 3; i++)
        count[i] = 0;
    for (i = 0; i < strlen(str); i++) 
    {
        if ((str[i] >='a' && str[i] <='z') || (str[i] >='A' && str[i] <='Z'))
            count[0]++; 
        else if (str[i] >= '0' && str[i] <= '9')
            count[1]++; 
        else
            count[2]++; 
    }
}
int main(void)
{
    char str[10000];
    int i, count[3]={0}; 
    char *c = "*****";
    char *c2 = "    ";
    printf("Input string:\n");
    gets(str);        
    Stat(str, count); 
    for(int i = 0;i<count[0];i++){
        printf("%s\n",c);
    }
      printf("\n");
    for(int i = 0;i<count[1];i++){
        printf("%s\n",c);
    }
    printf("\n");
    for(int i = 0;i<count[2];i++){
        printf("%s\n",c);
    }
                      
    
    
    return 0;
}
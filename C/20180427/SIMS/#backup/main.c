#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "config.h"

int main(int arg, char *argv)
{
    printf("-----------------Login to Student Information Management System--------------------\n");
    printf("name:");
    char t[20];
    char tt;
    
    while (((tt = getchar()) != '\n'))
    {
    }
    printf("password:");
     printf("\n");
    while (((tt = getch()) != '\n') )
    {  
        if (tt == '\177')
        {
            putchar('\177');
        }
        else
        printf("*%c",tt);
    }
}
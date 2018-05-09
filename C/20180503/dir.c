#include<unistd.h>
#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<dirent.h>
#include<string.h>
void printdir(char *dir, int depth)
{
	DIR *dp = opendir(dir);
	if(NULL == dp)
	{
		fprintf(stderr,"cannot open directory: %s\n", dir);
		return;
	} 
	chdir(dir);
	struct dirent *entry;
	struct stat statbuf;
	while((entry = readdir(dp)) != NULL)
	{
		stat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode))
		{if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
			continue;
			printf("%*s%s/\n",depth,"",entry->d_name);
			printdir(entry->d_name,depth+4);
		}
		else
			printf("%*s%s\n",depth,"",entry->d_name);
		//printf(“%*s” ,4,” *” ); 该函数表示输出“___*” ,前面输出 3 个空格。
		//如果是 printf(“%*s” ,4,“**” );则表示输出“__**” ， 前面输出 2 个空格。
	} 
	chdir("..");
	closedir(dp);
}

int main(){
	char *p;
	p = getcwd(NULL,0);
	printf("current working directory: %s\n" ,getcwd(NULL,0));
	chdir("/tmp");

	printf("current working directory: %s\n" ,getcwd(NULL,0));
	chdir(p);	
	printf("current working directory: %s\n" ,getcwd(NULL,0));
	printdir(p,2);
}

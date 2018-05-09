#include<unistd.h>
#include<stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<dirent.h>
#include<string.h>
#include <limits.h>
void print(char*p, char* find){
	DIR * dir = opendir(p);
	if(dir==NULL){
		perror("Open dir");
		return;
	}
	struct dirent *entry;
	char buf[512] = {0};
	while(entry = readdir(dir)){
		if(0==strcmp(entry->d_name,".")||0==strcmp(entry->d_name,".."))
			continue;
    if(0==strcmp(entry->d_name,find))
    { 

			sprintf(buf,"%s%s%s",p,"/",entry->d_name);
    
		printf("%s\n",buf);
    }
		if(entry->d_type==4) {
			sprintf(buf,"%s%s%s",p,"/",entry->d_name);
			print(buf,find);
		}
	}
}







int main(int argc,char**argv){
        if(argc!=3){
	printf("Wrong args");
	return -1;
	}
  int res;
  struct stat buf;
  stat(argv[1],&buf);
    res=buf.st_mode&S_IFDIR;
    if(res==S_IFDIR)
    {
      //  printf("%s为目录\n",argv[1]);
    }
    else
    {
        printf("%s不是目录\n",argv[1]);
        exit(1);
    }
    char tmp[256];
    realpath(argv[1],tmp);
 //   printf("%s",tmp);
	print(tmp,argv[2]);
	return 0;
}

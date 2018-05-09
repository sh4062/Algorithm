#include<unistd.h>
#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<dirent.h>
#include<string.h>

void print(char*p, int d){
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
		printf("%*s%s\n",d,"-",entry->d_name);
		if(entry->d_type==4) {
			sprintf(buf,"%s%s%s",p,"/",entry->d_name);
			print(buf,d+4);
		}
	}
}







int main(int argc,char**argv){
        if(argc!=2){
	printf("Wrong args");
	return -1;
	}
	print(argv[1],0);
	return 0;
}

#include<unistd.h>
#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include<dirent.h>
#include<string.h>

void ll(char* p){

}
int main(int argc,char**argv){
        if(argc!=2){
	printf("Wrong args");
	return -1;
	}
	ll(argv[1]);

}

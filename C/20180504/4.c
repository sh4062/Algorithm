#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <fcntl.h>
#include    <sys/mman.h>  

//获取文件大小，单位bytes  
size_t getFileSize(const char* path)  
{  
    struct stat buf;  
    if( stat(path, &buf)<0 )  
    {  
        perror("stat");  
        exit(1);  
    }  
    return buf.st_size;  
}  
int main(int argc, char *argv[])  
{  
    char* pmap=NULL;  
    size_t filesize=getFileSize("HW");  
    int fd=open("HW", O_RDONLY);  
    if( fd<0 )  
    {  
        perror("open");  
        exit(1);  
    }  
    pmap=(char*)mmap(NULL, filesize, PROT_READ, MAP_SHARED, fd, 0);  
    if( MAP_FAILED==pmap )  
    {  
        perror("mmap");  
        exit(1);  
    }  
      
    write(1, pmap, filesize);  
    close(fd);  
    munmap(pmap, filesize);  
    return 0;  
}  
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
typedef struct stu
{
    int id;
    char name[20];
    double score;

} stu, *pstu;

int main()
{
    stu tmp[3] ;
    tmp[0].id = 1;
    tmp[1].id = 2;
    tmp[2].id = 3;
    tmp[0].score = 100;
    tmp[1].score = 99;
    tmp[2].score = 98;
    strcpy(tmp[0].name, "Turtle");
    strcpy(tmp[1].name, "Pig");
    strcpy(tmp[2].name, "Rabbit");
    int fd = open("./text.txt", O_CREAT | O_APPEND | O_RDWR, 0777);
    if (-1 == fd)
    {
        perror("open failed!\n");
        exit(-1);
    }
    int fw;
    
    fw = write(fd, &tmp, sizeof(tmp));
  
   
    
    if (-1 == fw)
    {
        perror("write failed!\n");
        exit(-1);
    }
    lseek(fd,0,SEEK_SET);
    int buf1 = 0;
    char buf2[21] = {0};
    double buf3 = 0;
    for(int i = 0;i<3;i++){
        read(fd, &buf1, sizeof(int) );
        read(fd, buf2, sizeof(buf2) - 1);
        read(fd, &buf3, sizeof(double) );
        printf("%d", buf1);
        printf("%s", buf2);
        printf("%lf", buf3);
    }
    close(fd);
   
    

    return 0;
}

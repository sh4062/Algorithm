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

char *tts(int c)
{
  if (c == 0000)
  {
    static char res1[4] = "---";
    return res1;
  }
  if (c == 0001)
  {
    static char res2[4] = "--x";
    return res2;
  }
  if (c == 10)
  {
    static char res3[4] = "-w-";
    return res3;
  }
  if (c == 100)
  {
    static char res4[4] = "r--";
    return res4;
  }
  if (c == 11)
  {
    static char res5[4] = "-wx";
    return res5;
  }
  if (c == 101)
  {
    static char res6[4] = "r-x";
    return res6;
  }
  if (c == 110)
  {
    static char res7[4] = "rw-";
    return res7;
  }
  if (c == 111)
  {
    static char res8[4] = "rwx";
    return res8;
  }
}
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Wrong args");
    return -1;
  }
  int res;
  struct stat buf;
  stat(argv[1], &buf);
  res = buf.st_mode & S_IFDIR;
  if (res == S_IFDIR)
  {
    //  printf("%s为目录\n",argv[1]);
  }
  else
  {
    printf("%s不是目录\n", argv[1]);
    exit(1);
  }
  DIR *dir = opendir(argv[1]);
  if (dir == NULL)
  {
    perror("Open dir");
    return -1;
  }

  struct dirent *entry;
 
  while (entry = readdir(dir))
  {
    int ret = 0;
    ret = stat(entry->d_name, &buf);
    if (ret == -1)
    {
      perror("stat");
      return -1;
    }
    int n = buf.st_mode;
    // char stmode[20] = {0};
    // memset(stmode,0,sizeof(stmode));
    // sprintf(stmode,"%x",buf.st_mode);
    // int st1 = st%10;
    // st/=10;
    // int st2 = st%10;
    // st/=10;
    // int st3 = st%10;
    // char st11[5] = {0};
    // strcpy(st11, tts(st1));
    // char st12[5] = {0};
    // strcpy(st12, tts(st2));
    // char st13[5] = {0};
    // strcpy(st13, tts(st3));
    int arr[20] = {0};
    int i;
    for (i = 20 - 1; i >= 0; i--) //对数组从后往前赋值
    {
      arr[i] = 0;
     
    }
    
    for (i = 20 - 1; i >= 0; i--) //对数组从后往前赋值
    {
      arr[i] = n % 2;
      n = n / 2;
      if(n==0)break;
    }
     int st1 = arr[19]+arr[18]*10+arr[17]*100;
    
    int st2 =  arr[16]+arr[15]*10+arr[14]*100;
    
    int st3 = arr[13]+arr[12]*10+arr[11]*100;


    char tim[128] = {0};
    strcpy(tim, ctime(&buf.st_mtime) + 4);
    tim[strlen(tim) - 9] = '\0';
     printf("%s%s%s  %4ld %s %s %4ld %s %s\n", tts(st1), tts(st2), tts(st3), buf.st_nlink, getpwuid(buf.st_uid)->pw_name, getgrgid(buf.st_uid)->gr_name, buf.st_size, tim, entry->d_name);
  
  
  }

  return 0;
}

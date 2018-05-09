#include "fun.h"//孤儿的父进程不是1 因为ubuntu用systemd代替init
#include<signal.h>
int main(void)
{
        pid_t pid ;
        //signal(SIGCHLD,SIG_IGN);
        printf("before fork pid:%d\n",getpid());
        int abc = 10;
        pid = fork();
        if(pid == -1)
        {
                perror("tile");
                return -1;
        }
        if(pid > 0)
        {
                abc++;
                printf("parent:pid:%d \n",getpid());
                printf("abc:%d \n",abc);
//                pid_t pid2 = wait(NULL);
//                printf("asdasdasd%d",pid2);
                int wstatus;
                pid_t res = waitpid(-1, &wstatus, WUNTRACED | WCONTINUED);
                printf("asdasdasd:%d\n",WEXITSTATUS(wstatus));
                sleep(10);
        }
        else if(pid == 0){
                abc++;
                printf("child:%d,parent: %d\n",getpid(),getppid());
                printf("abc:%d",abc);
                exit(10);
        }
        printf("fork after...\n");}

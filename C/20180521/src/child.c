#include "func.h"

void make_child(pData p,int num)
{
	int i;
	int fds[2];
	int ret;
	pid_t pid;
	for(i=0;i<num;i++)
	{
		ret=socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
		if(-1==ret)
		{
			perror("socketpair");
			return;
		}
		pid=fork();
		if(0==pid)
		{
			close(fds[1]);
			child_handle(fds[0]);
		}
		close(fds[0]);
		p[i].pid=pid;
		p[i].fd=fds[1];//fds[1]是即可读，又可写
	}
}
void sigfunc(int signum)
{
	printf("%d is coming\n",signum);
}
void child_handle(int fd)
{
	char flag;
	int new_fd;
	int i;
        printf("!!!\n");
	//for(i=0;i<32;i++)
	//{
        //		signal(i,sigfunc);
	//}
	while(1)
	{
		recv_fd(fd,&new_fd);
		trans_file(new_fd);
		write(fd,&flag,1);//通知主进程完成任务
	}
}

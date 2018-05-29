#include "func.h"

int main()
{
	int fds[2];
	pipe(fds);//初始化管道
	printf("fds[0]=%d,fds[1]=%d\n",fds[0],fds[1]);
	if(!fork())
	{
		close(fds[1]);
		int fd;
		read(fds[0],&fd,sizeof(int));
		printf("child fd=%d\n",fd);
		char buf[128]={0};
		int ret;
		ret=read(fd,buf,sizeof(buf));
		printf("child ret=%d,buf=%s\n",ret,buf);

	}else{
		close(fds[0]);
		int fd;
		fd=open("file",O_RDWR);
		printf("parent fd=%d\n",fd);
		write(fds[1],&fd,sizeof(int));
		wait(NULL);
		return 0;
	}
}

#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("./client IP PORT\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));//将端口号转换为网络字节序
	ser.sin_addr.s_addr=inet_addr(argv[1]);//将点分十进制的IP地址转为网络字节序
	int ret;
	ret=connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	char buf[1000]={0};
	int len;
	recv(sfd,&len,sizeof(int),0);
	recv(sfd,buf,len,0);//接收文件名
	int fd;
	fd=open(buf,O_RDWR|O_CREAT,0666);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	while(1)
	{
		recv_n(sfd,(char*)&len,sizeof(int));
		if(len>0)
		{
			recv_n(sfd,buf,len);
			write(fd,buf,len);
		}else{
			printf("file recv success\n");
			break;
		}
	}
	close(sfd);
	return 0;
}

#include "fun.h"

int send_n(int sfd,char* p,int len)
{
	int ret;
	int total=0;
	while(total<len)
	{
		ret=send(sfd,p+total,len-total,0);
		total=total+ret;
	}
	return 0;
}

int recv_n(int sfd,char* p,int len)
{
	int ret;
	int total=0;
	while(total<len)
	{
		ret=recv(sfd,p+total,len-total,0);
		total=total+ret;
	}
	return 0;
}


void trans_file(int sfd, char *FILENAME)
{
	train t;
	t.len=strlen(FILENAME);
	strcpy(t.buf,FILENAME);
	//把文件名发送给对端
	send(sfd,&t,4+t.len,0);
	int fd;
	fd=open(FILENAME,O_RDWR);
	while((t.len=read(fd,t.buf,sizeof(t.buf)))>0)
	{
		send_n(sfd,(char*)&t,4+t.len);
	}
	send(sfd,&t,4+t.len,0);//开一趟空火车
	close(sfd);
}

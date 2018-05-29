#include "func.h"

int main(int argc,char* argv[])
{
	if(argc!=4)
	{
		printf("./server IP PORT PROCESS_NUM\n");
		return -1;
	}
	int pro_num=atoi(argv[3]);
	pData p=(pData)calloc(pro_num,sizeof(Data));
	make_child(p,pro_num);
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	int reuse=1;
	int ret;
	ret=setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int));
	if(-1==ret)
	{
		perror("setsockopt");
		return -1;
	}
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));//将端口号转换为网络字节序
	ser.sin_addr.s_addr=inet_addr(argv[1]);//将点分十进制的IP地址转为网络字节序
	ret=bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	//开始监控sfd及每一个子进程管道的对端
	int epfd=epoll_create(1);
	struct epoll_event event,*evs;
	evs=(struct epoll_event*)calloc(pro_num+1,sizeof(struct epoll_event));
	event.events=EPOLLIN;
	event.data.fd=sfd;
	epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
	int i,j;
	for(i=0;i<pro_num;i++)
	{
		event.data.fd=p[i].fd;
		epoll_ctl(epfd,EPOLL_CTL_ADD,p[i].fd,&event);
	}
	listen(sfd,10);
	int rnum;
	int new_fd;
	struct sockaddr_in client;
	socklen_t len;
	char flag;
	while(1)
	{
		rnum=epoll_wait(epfd,evs,pro_num+1,-1);
		for(i=0;i<rnum;i++)
		{
			if(sfd==evs[i].data.fd)
			{
				len=sizeof(struct sockaddr);
				new_fd=accept(sfd,(struct sockaddr*)&client,&len);
				printf("client ip=%s,port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
				for(j=0;j<pro_num;j++)
				{
					if(0==p[j].busy)
					{
						send_fd(p[j].fd,new_fd);
						close(new_fd);
						p[j].busy=1;//子进程设为忙碌
						printf("%d is busy\n",p[j].pid);
						break;
					}
				}
			}
			for(j=0;j<pro_num;j++)
			{
				if(p[j].fd==evs[i].data.fd)
				{
					read(p[j].fd,&flag,1);
					p[j].busy=0;
					printf("%d is not busy\n",p[j].pid);
				}
			}
		}
	}
}

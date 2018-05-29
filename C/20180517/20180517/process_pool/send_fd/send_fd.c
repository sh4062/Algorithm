#include "func.h"
void send_fd(int pfd,int fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(msg));
	struct iovec iov[2];
	char buf1[10]="hello";
	char buf2[10]="world";
	iov[0].iov_base=buf1;
	iov[0].iov_len=5;
	iov[1].iov_base=buf2;
	iov[1].iov_len=5;
	msg.msg_iov=iov;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr *)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	*(int*)CMSG_DATA(cmsg)=fd;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret;
	ret=sendmsg(pfd,&msg,0);
	if(-1==ret)
	{
		perror("sendmsg");
		return;
	}
}
void recv_fd(int pfd,int* fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(msg));
	struct iovec iov[2];
	char buf1[10]="hello";
	char buf2[10]="world";
	iov[0].iov_base=buf1;
	iov[0].iov_len=5;
	iov[1].iov_base=buf2;
	iov[1].iov_len=5;
	msg.msg_iov=iov;
	msg.msg_iovlen=2;
	struct cmsghdr *cmsg;
	int len=CMSG_LEN(sizeof(int));
	cmsg=(struct cmsghdr *)calloc(1,len);
	cmsg->cmsg_len=len;
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	msg.msg_control=cmsg;
	msg.msg_controllen=len;
	int ret;
	ret=recvmsg(pfd,&msg,0);
	if(-1==ret)
	{
		perror("recvmsg");
		return;
	}
	*fd=*(int*)CMSG_DATA(cmsg);
}

int main()
{
	int fds[2];
	socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
	printf("fds[0]=%d,fds[1]=%d\n",fds[0],fds[1]);
	if(!fork())
	{
		close(fds[1]);
		int fd;
		recv_fd(fds[0],&fd);
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
		send_fd(fds[1],fd);
		wait(NULL);
		return 0;
	}
}

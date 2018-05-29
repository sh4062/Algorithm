#include "func.h"
void send_fd(int pfd,int fd)
{
	struct msghdr msg;
	bzero(&msg,sizeof(msg));
        char buf[2];
	struct iovec iov[1];
	iov->iov_base=buf;
	iov->iov_len=1;
	msg.msg_iov=iov;
	msg.msg_iovlen=1;
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
        char buf[2];
	struct iovec iov[1];
	iov->iov_base=buf;
	iov->iov_len=1;
	msg.msg_iov=iov;
	msg.msg_iovlen=1;
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

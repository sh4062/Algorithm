
#include "utils.h"
int fd_Setnonblocking(int fd)
{
	int op;

	op = fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, op | O_NONBLOCK);

	return op;
}

int recv_n(int sfd, char *p, int len)
{
	int ret;
	int total = 0;
	while (total < len)
	{
		ret = recv(sfd, p + total, len - total, 0);
		if (ret == 0)
		{
			perror("server recv");
			return -1;
		}
		total = total + ret;
	}
	return 0;
}

int send_n(int sfd, char *p, int len)
{
	int ret;
	int total = 0;
	while (total < len)
	{
		ret = send(sfd, p + total, len - total, 0);
		if (ret == -1)
		{
			perror("server recv");
			return -1;
		}
		total = total + ret;
	}
	return 0;
}

void trans_file(int sfd, char *filename, char *path)
{
	train t;

	t.len = strlen(filename);
	strcpy(t.buf, filename);
	//把文件名发送给对端
	int ret = send(sfd, &t, 4 + t.len, 0);
	if(ret == 0){
		perror("tarnsfile send"); 
		return (void)0;
	}
	struct stat filesize;
	stat(path, &filesize);

	memcpy(t.buf, &filesize.st_size, sizeof(off_t));
	t.len = sizeof(off_t);
	ret = send_n(sfd, (char *)&t, 4 + t.len);
	if(ret == -1){
		perror("tarnsfile send"); 
		return (void)0;
	}
	printf("aaaaa\n");
	int fd;
	fd = open(path, O_RDWR);
	while ((t.len = read(fd, t.buf, sizeof(t.buf))) > 0)
	{
		ret = send_n(sfd, (char *)&t, 4 + t.len);
		if(ret == -1){
		perror("tarnsfile send"); 
		return (void)0;
	}
	}
	printf("bbbbb\n");
	t.len = 0;
	//send(sfd, &t, 4 + t.len, 0); //开一趟空火车
	//close(sfd);
}

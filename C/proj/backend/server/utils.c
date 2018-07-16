
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

void trans_file(int sfd, char *filename, char *path, off_t filesize_truncated)
{
	train t;

	t.len = strlen(filename);
	strcpy(t.buf, filename);
	//把文件名发送给对端
	int ret = send(sfd, &t, 4 + t.len, 0);
	if (ret == 0)
	{
		perror("tarnsfile send");
		return (void)0;
	}
	struct stat filesize;
	stat(path, &filesize);

	memcpy(t.buf, &filesize.st_size, sizeof(off_t));
	char *bufp;

	t.len = sizeof(off_t);
	ret = send_n(sfd, (char *)&t, 4 + t.len);
	if (ret == -1)
	{
		perror("tarnsfile send");
		return (void)0;
	}
	printf("aaaaa\n");
	int fd;
	fd = open(path, O_RDWR);
	if (filesize.st_size > 1000000)
	{
		bufp = mmap(NULL, filesize.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	}
	if (filesize_truncated != 0)
	{
		lseek(fd, filesize_truncated, SEEK_SET);
	}
	if (filesize.st_size <= 1000000)
	{
		while ((t.len = read(fd, t.buf, sizeof(t.buf))) > 0)
		{
			ret = send_n(sfd, (char *)&t, 4 + t.len);
			if (ret == -1)
			{
				perror("tarnsfile send");
				return (void)0;
			}
		}
	}
	else
	{
		printf("%ld\n",filesize_truncated);
		char *send_p;
		long int count = filesize_truncated;
		send_p = bufp + filesize_truncated;
		t.len = sizeof(t.buf);
		printf("sadasdasdas\n");
		while ((filesize.st_size - count) >= sizeof(t.buf))
		{
			memcpy(send_p, t.buf, sizeof(t.buf));
			ret = send_n(sfd, (char *)&t, 4 + t.len);
			if (ret == -1)
			{
				perror("tarnsfile send");
				return (void)0;
			}
			send_p += sizeof(t.buf);
			count += sizeof(t.buf);
		}
		t.len = filesize.st_size - count;
		memcpy(send_p, t.buf, filesize.st_size - count);
		ret = send_n(sfd, (char *)&t, 4 + t.len);
		if (ret == -1)
		{
			perror("tarnsfile send");
			return (void)0;
		}
		printf("sadasdasdas\n");

		munmap((void *)bufp, filesize.st_size);
	}
	printf("bbbbb\n");
	t.len = 0;
	//send(sfd, &t, 4 + t.len, 0); //开一趟空火车
	//close(sfd);
}


#include "EpollPoller.h"
#include "Acceptor.h"
#include <assert.h>
//预览数据
inline size_t recvPeek(int sockfd, void * buf, size_t len)
{
	int nread;
	do
	{
		nread = ::recv(sockfd, buf, len, MSG_PEEK);
	}while(nread == -1 && errno == EINTR);
	return nread;
}

//通过预览数据，判断conn是否关闭
inline bool isConnectionClosed(int sockfd)
{
	char buf[1024];
	int nread = recvPeek(sockfd, buf, sizeof(buf));
	if(-1 == nread)
	{
		perror("recvPeek--- ");
		return true;
	}
	return (0 == nread);
}
inline int createEpollFd()
{
	int efd = ::epoll_create1(0);
	if(-1 == efd)
	{
		perror("epoll_create1 error");
		exit(EXIT_FAILURE);
	}
	return efd;
}

inline int createEventFd()
{
	int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
	if(-1 == evtfd)
	{
		perror("eventfd create error");
	}
	return evtfd;
}

inline void addEpollFdRead(int efd, int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	int ret = epoll_ctl(efd, EPOLL_CTL_ADD, fd, &ev);
	if(-1 == ret)
	{
		perror("epoll_ctl add error");
		exit(EXIT_FAILURE);
	}
}

inline void delEpollReadFd(int efd, int fd)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	int ret = epoll_ctl(efd, EPOLL_CTL_DEL, fd, &ev);
	if(-1 == ret)
	{
		perror("epoll_ctl del error");
		exit(EXIT_FAILURE);
	}
}
namespace oh
{

EpollPoller::EpollPoller(Acceptor &acceptor)
	: acceptor_(acceptor), epollfd_(createEpollFd()), listenfd_(acceptor_.fd()), isLooping_(false), eventsList_(1024)
{
	addEpollFdRead(epollfd_, listenfd_);
}

EpollPoller::~EpollPoller()
{
	::close(epollfd_);
} /*  */

void EpollPoller::loop()
{
	isLooping_ = true;
	while (isLooping_)
	{
		waitEpollfd();
	}
}

void EpollPoller::unloop()
{
	if (isLooping_)
		isLooping_ = false;
}

void EpollPoller::setConnectionCallback(EpollCallback cb)
{
	onConnectionCb_ = cb;
}

void EpollPoller::setMessageCallback(EpollCallback cb)
{
	onMessageCb_ = cb;
}

void EpollPoller::setCloseCallback(EpollCallback cb)
{
	onCloseCb_ = cb;
}

void EpollPoller::waitEpollfd()
{
	int nready;
	do
	{
		nready = ::epoll_wait(epollfd_,
							  &(*eventsList_.begin()),
							  eventsList_.size(),
							  5000);
	} while (nready == -1 && errno == EINTR);

	if (nready == -1)
	{
		perror("epoll_wait error");
		exit(EXIT_FAILURE);
	}
	else if (nready == 0)
	{
		printf("epoll_wait timeout\n");
	}
	else
	{
		//做一个扩容的操作
		if (nready == static_cast<int>(eventsList_.size()))
		{
			eventsList_.resize(eventsList_.size() * 2);
		}

		//遍历每一个激活的文件描述符
		for (int idx = 0; idx != nready; ++idx)
		{
			if (eventsList_[idx].data.fd == listenfd_)
			{
				if (eventsList_[idx].events & EPOLLIN)
				{
					handleConnection();
				}
			}
			else
			{
				if (eventsList_[idx].events & EPOLLIN)
				{
					handleMessage(eventsList_[idx].data.fd);
				}
			}
		} //end for
	}	 //end else
}

void EpollPoller::handleConnection()
{
	int peerfd = acceptor_.accept();
	addEpollFdRead(epollfd_, peerfd);

	TcpConnectionPtr conn(new TcpConnection(peerfd));
	//...给客户端发一个欢迎信息==> 挖一个空: 等...
	//conn->send("welcome to server.\n");
	conn->setConnectionCallback(onConnectionCb_);
	conn->setMessageCallback(onMessageCb_);
	conn->setCloseCallback(onCloseCb_);

	std::pair<ConnectionMap::iterator, bool> ret;
	ret = connMap_.insert(std::make_pair(peerfd, conn));
	assert(ret.second == true);
	(void)ret;
	//connMap_[peerfd] = conn;

	conn->handleConnectionCallback();
}

void EpollPoller::handleMessage(int peerfd)
{
	bool isClosed = isConnectionClosed(peerfd);
	ConnectionMap::iterator it = connMap_.find(peerfd);
	assert(it != connMap_.end());

	if (isClosed)
	{
		it->second->handleCloseCallback();
		delEpollReadFd(epollfd_, peerfd);
		connMap_.erase(it);
	}
	else
	{
		it->second->handleMessageCallback();
	}
}

} // namespace oh

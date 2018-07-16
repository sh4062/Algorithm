#include "TcpServer.h"
#include "InetAddress.h"
#include "Socket.h"
#include <iostream>
using std::cout;
using std::endl;
// inline int createSocketFd()
// {
// 	int fd = ::socket(AF_INET, SOCK_STREAM, 0);
// 	if(fd == -1)
// 	{
// 		perror("socket create error!");
// 	}
// 	return fd;
// }
namespace oh
{

TcpServer::TcpServer(const string &ip, unsigned short port)
	: acceptor_(createSocketFd(), InetAddress(ip.c_str(), port)), poller_(acceptor_)
{
}

void TcpServer::start()
{
	acceptor_.ready();
	poller_.setConnectionCallback(connectionCallback_);
	poller_.setMessageCallback(messageCallback_);
	poller_.setCloseCallback(closeCallback_);
	poller_.loop();
}

void TcpServer::stop()
{
	poller_.unloop();
}

void TcpServer::setConnectionCallback(TcpServerCallback cb)
{
	connectionCallback_ = cb;
}
void TcpServer::setMessageCallback(TcpServerCallback cb)
{
	messageCallback_ = cb;
}
void TcpServer::setCloseCallback(TcpServerCallback cb)
{
	closeCallback_ = cb;
}

} // namespace oh

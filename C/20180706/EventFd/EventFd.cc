#include "EventFd.h"
using namespace m;
#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <sys/eventfd.h>
#include <iostream>
int createEventfd()
{
    int fd = ::eventfd(0, 0);
    if (fd == -1)
    {
        perror("eventfd create");
    }
    return fd;
}

Eventfd::Eventfd(Callback &&cb)
    : _cb(std::move(cb)), _fd(createEventfd()), _isStarted(false)
{
}

void Eventfd::stop()
{
    _isStarted = false;
}
void Eventfd::start()
{
    _isStarted = true;

    struct pollfd pfd;
    pfd.fd = _fd;
    pfd.events = POLLIN;

    while (_isStarted)
    {
        int nready = ::poll(&pfd, 1, 5000);
        if (nready == -1 && errno == EINTR)
            continue;
        else if (nready == -1)
        {
            perror(">>> poll error!");
            exit(EXIT_FAILURE);
        }
        else if (nready == 0)
        {
            std::cout << ">>> poll timeout!" << std::endl;
        }
        else
        {
            if (pfd.revents & POLLIN)
            {
                handleRead(); //处理eventfd
                if (_cb)
                    _cb(); //执行任务
            }
        }
    }
}

void Eventfd::wakeup()
{
    uint64_t one = 1;
    int nret = ::write(_fd, &one, sizeof(one));
    if (nret != sizeof(uint64_t))
    {
        perror("write error");
    }
}
void Eventfd::handleRead()
{
    uint64_t howmany;
    int nret = ::read(_fd, &howmany, sizeof(uint64_t));
    if (nret != sizeof(uint64_t))
    {
        perror("read error");
    }
}
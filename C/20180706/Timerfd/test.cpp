#include "EventFd.h"
#include "Thread.h"
using namespace m;
#include <unistd.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

void getNumber()
{
    srand(time(NULL));
    int number = rand() % 100;
    cout << "subThread: " << pthread_self() << ">>> number = " << number << endl;
}

int main()
{
    m::Eventfd eventfd(getNumber);
    m::Thread subthread(std::bind(&m::Eventfd::start, &eventfd));
    subthread.start();
    ::sleep(2);

    int cnt = 10;
    while (cnt--)
    {
        eventfd.wakeup(); //主线程通知子线程完成任务
        sleep(1);
    }
    sleep(3);
    eventfd.stop();

    subthread.join();

    return 0;
}
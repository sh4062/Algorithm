#include "Mutex.h"
namespace thread_n
{
MutexLock::MutexLock()
{
    pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock()
{
    pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
    pthread_mutex_lock(&_mutex);
    _islock = true;
}

void MutexLock::unlock()
{
    pthread_mutex_unlock(&_mutex);
    _islock = false;
}
} // namespace thread_n
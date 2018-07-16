#include "Socket.h"


#include <netinet/in.h>
#include <netinet/tcp.h>
#include <strings.h>  // bzero
#include <stdio.h>  // snprintf
using namespace m;
using namespace m::net;

Socket::~Socket(){
    ::close(_sockfd);
}
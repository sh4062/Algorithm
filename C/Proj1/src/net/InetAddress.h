#include <netinet/in.h>
#include <string>
using namespace std;
namespace oh
{
class InetAddress
{
  public:
    InetAddress(unsigned short);
    InetAddress(const char *ip, unsigned short);
    InetAddress(const struct sockaddr_in &addr);
    string ip() const;
    unsigned short port() const;

  private:
    struct sockaddr_in _addr;
};
} // namespace oh
#ifndef _OH_S_C_SERVER_H_
#define _OH_S_C_SERVER_H_
#include "Threadpool.h"
#include "Configuration.h"
#include "TcpServer.h"
#include <set>
#include <map>
using namespace std;
struct MyResult
{
  string _word;
  int _iFreq;
  int _iDist;
};
namespace oh
{
class SpellcorrectServer
{
public:
  SpellcorrectServer(const string &
                         cfgFileName);
  void start();
  vector<pair<string, int>> &getDict();
  map<string, set<int>> &getIndexTable();
 
private:
  void onMessage(const oh::TcpConnectionPtr &conn);
  void onConnection(const oh::TcpConnectionPtr &conn);
  void onClose(const oh::TcpConnectionPtr &conn);
  Configuration &_conf;
  TcpServer _tcpServer;
  Threadpool _threadpool;
};

} // namespace oh
#endif
#include "SpellcorrectServer.h"
#include "Configuration.h"
#include "Threadpool.h"
#include "Mydict.h"
#include "MyTask.h"
#include "InetAddress.h"
#include "CacheManager.h"
#include <string>
#include <functional>

using namespace std::placeholders;
using std::unique_ptr;
using namespace oh;
inline Configuration &createConfiguration(const string &cfgFileName)
{
    static Configuration Configuration(cfgFileName);
    return Configuration;
}
SpellcorrectServer::SpellcorrectServer(const string &cfgFileName)
    : _conf(createConfiguration(cfgFileName)), _threadpool(std::stoi(_conf._configMap["threadNum"]), std::stoi(_conf._configMap["queSize"])), 
    _tcpServer(_conf._configMap["ip"], std::stoi(_conf._configMap["port"]))
{
    //std::stoi(_conf._configMap["a"])
    MyDict *a = MyDict::createInstance();
    a->init0();
    //Threadpool pool(10, 10);
    //oh::InetAddress addr("192.168.4.16", 9999);
    //TcpServer tcpserver(addr.ip(), addr.port());
}
void SpellcorrectServer::onConnection(const oh::TcpConnectionPtr &conn)
{

    cout << conn->toString() << "has connected!" << endl;
    conn->send("hello, welcome to SpellCorrect Server.\r\n");
}

void SpellcorrectServer::onMessage(const oh::TcpConnectionPtr &conn)
{
    std::string s(conn->receive());
    cout << "server: " << s << endl;
    MyTask b(s, conn->get_fd(), conn);
    oh::SpellcorrectServer::_threadpool.addTask(&b);
    // sleep(3);
    // string res;
    // //cout << b._resultQue.top().get_word() << endl;
    // res = res + b._resultQue.top().get_word() + '\n';
    // b._resultQue.pop();
    // //cout << b._resultQue.top().get_word() << endl;
    // res = res + b._resultQue.top().get_word() + '\n';
    // b._resultQue.pop();
    // //cout << b._resultQue.top().get_word() << endl;
    // res = res + b._resultQue.top().get_word() + '\n';
    // cout << res << endl;

    // // b.queryIndexTable();
    // // string res;

    // // cout << res<< endl;
    // conn->send(res);
    // //做业务逻辑的处理
    // pool.addTask(&b);
}

void SpellcorrectServer::onClose(const oh::TcpConnectionPtr &conn)
{
    printf("%s close\n", conn->toString().c_str());
}

void SpellcorrectServer::start()
{
    _threadpool.start();
    _tcpServer.setConnectionCallback(std::bind(&SpellcorrectServer::onConnection, this, _1));
    _tcpServer.setMessageCallback(std::bind(&SpellcorrectServer::onMessage, this, _1));
    _tcpServer.setCloseCallback(std::bind(&SpellcorrectServer::onClose, this, _1));
    _tcpServer.start();

    cout << "MainThread: " << pthread_self() << endl;
}
vector<pair<string, int>> &SpellcorrectServer::getDict()
{
    MyDict *a = MyDict::createInstance();
    return a->_dict;
}
map<string, set<int>> &SpellcorrectServer::getIndexTable()
{
    MyDict *a = MyDict::createInstance();
    return a->_index_table;
}

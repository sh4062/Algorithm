#ifndef _OH_MY_TASK_H_
#define _OH_MY_TASK_H_
#include <string>
#include <queue>
#include <set>
#include "Threadpool.h"
#include "TcpConnection.h"
#include "CacheManager.h"
#include <iostream>
using namespace std;
namespace oh
{
class MyResult
{
public:
  MyResult(std::string word, int dist, int fre)
      : m_word(word), m_dist(dist), m_frequece(fre)
  {
  }
  std::string get_word() const
  {
    return m_word;
  }
  int get_dist() const
  {
    return m_dist;
  }
  int get_fre() const
  {
    return m_frequece;
  }

private:
  std::string m_word;
  int m_dist;
  int m_frequece;
};
class MyCompare //定义比较方法，先比较dist,dist小的在前面，如果dist相等，再比较fre，fre大的在前面
{
public:
  bool operator()(MyResult left, MyResult right) const
  {
    if (left.get_dist() == right.get_dist())
      return left.get_fre() < right.get_fre();
    return left.get_dist() > right.get_dist();
  }
};
class MyTask : public Task
{
public:
  MyTask(const string &queryWord, int peerfd,const TcpConnectionPtr &conn);
  void process();
  void queryIndexTable();
  void statistic(set<int> &iset);
  int distance(const string &source, const string &target);
  void response();
  priority_queue<MyResult,
                 vector<MyResult>,
                 MyCompare>
      _resultQue;

private:
  string _queryWord; //等查询的单词
  int _peerfd;       //与客户端进行连接的文件描述符
  const TcpConnectionPtr &_conn;
};
} // namespace oh
#endif
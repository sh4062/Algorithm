#include "MyTask.h"
#include "Mydict.h"
#include "CacheManager.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace oh;
MyTask::MyTask(const string &queryWord, int peerfd, const TcpConnectionPtr &conn)
    : _queryWord(queryWord), _peerfd(peerfd), _resultQue(), _conn(conn)
{
    cout << "MyTask\n";
}
void MyTask::process()
{
    cout << ">>>MyTask::process subThread: " << pthread_self() << endl;
    // TcpConnection conn(_peerfd);
    //  std::string s(conn.receive());
    // cout << "server: " << s << endl;
    // MyTask b(s, 0);
    string res;
    Cache tmp = CacheManage::getCache(1);
    if (tmp._hashMap.find(this->_queryWord)!=tmp._hashMap.end())
    {
        res = tmp._hashMap[this->_queryWord];
    }
    else
    {

        this->queryIndexTable();
        //cout << b._resultQue.size() << endl;

        //cout << b._resultQue.top().get_word() << endl;
        res = res + this->_resultQue.top().get_word() + '\n';
        this->_resultQue.pop();
        //cout << b._resultQue.top().get_word() << endl;
        res = res + this->_resultQue.top().get_word() + '\n';
        this->_resultQue.pop();
        //cout << b._resultQue.top().get_word() << endl;
        res = res + this->_resultQue.top().get_word() + '\n';
    }
    cout << res << endl;
    _conn->send(res);
    //做业务逻辑的处理
}
void MyTask::queryIndexTable()
{
    //ifstream ifs("index.dict");
    //cout<<_queryWord.substr(1, 1)<<'\n';
    set<string> tmp_set;
    for (int i = 0; i < _queryWord.size(); i++)
    {
        for (auto &l : MyDict::_index_table[_queryWord.substr(i, 1)])
        { //cout<<MyDict::_index_table[_queryWord.substr(i, 1)].size()<<'\n';
            int dis = distance(MyDict::_dict[l].first, _queryWord);

            if (tmp_set.find(MyDict::_dict[l].first) == tmp_set.end())
            {
                tmp_set.insert(MyDict::_dict[l].first);
                MyResult tmp(MyDict::_dict[l].first, dis, MyDict::_dict[l].second);
                _resultQue.push(tmp);
            }
        }
    }
    //ifs.close();
}
//进行计算
void MyTask::statistic(set<int> &iset)
{
}
//计算最小编辑距离
int MyTask::distance(const string &source, const string &target)
{
    int n = source.length();
    int m = target.length();
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    //Construct a matrix
    typedef vector<vector<int>> Tmatrix;
    Tmatrix matrix(n + 1);
    for (int i = 0; i <= n; i++)
        matrix[i].resize(m + 1);

    //step 2 Initialize

    for (int i = 1; i <= n; i++)
        matrix[i][0] = i;
    for (int i = 1; i <= m; i++)
        matrix[0][i] = i;

    //step 3
    for (int i = 1; i <= n; i++)
    {
        const char si = source[i - 1];
        //step 4
        for (int j = 1; j <= m; j++)
        {

            const char dj = target[j - 1];
            //step 5
            int cost;
            if (si == dj)
            {
                cost = 0;
            }
            else
            {
                cost = 1;
            }
            //step 6
            const int above = matrix[i - 1][j] + 1;
            const int left = matrix[i][j - 1] + 1;
            const int diag = matrix[i - 1][j - 1] + cost;
            matrix[i][j] = min(above, min(left, diag));
        }
    } //step7
    return matrix[n][m];
}
void MyTask::response()
{
}
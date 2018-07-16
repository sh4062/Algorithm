/*
 * File: test.cpp
 * Project: pool
 * File Created: Wednesday, 4th July 2018 10:27:59 am
 * Author: max (mx0666@163.com)
 * -----
 * Last Modified: Wednesday, 4th July 2018 10:28:00 am
 * Modified By: max (mx0666@163.com>)
 * -----
 * Copyright 2018 - 2018 Outer Heaven
 */

// #include "Configuration.h"
#include "DictProducer.h"
#include "Mydict.h"
#include "MyTask.h"
#include "Thread.h"
#include "TaskQueue.h"
#include "TcpServer.h"
#include "Threadpool.h"
#include "Acceptor.h"
#include "Socket.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <memory>
#include "CacheManager.h"
#include "SpellcorrectServer.h"
using std::cout;
using std::endl;
using std::unique_ptr;
using namespace oh;
// int main(){
// 	Configuration a("../conf/config");
// 	a.getConfigMap();
// }
// int main(){
// 	DictProducer a("../data");
// 	a.build_en_dict();
// 	a.show_dict();
// 	a.store_dict("./dict.dict");

// }
// void test_dict(TaskQueue &tq)
// {
// 	MyDict *a = MyDict::createInstance();
// 	a->init0();
// 	string test;
// 	cout << "Input string!\n";
// 	cin >> test;
// 	MyTask b(test, 0);
// 	b.queryIndexTable();
// 	cout << b._resultQue.size() << endl;
// 	cout << b._resultQue.top().get_word() << endl;
// 	b._resultQue.pop();
// 	cout << b._resultQue.top().get_word() << endl;
// 	b._resultQue.pop();
// 	cout << b._resultQue.top().get_word() << endl;
// }

// void onConnection(const oh::TcpConnectionPtr &conn)
// {
// 	cout << conn->toString() << "has connected!" << endl;
//     conn->send("hello, welcome to SpellCorrect Server.\r\n");
// }

// void onMessage(const oh::TcpConnectionPtr &conn)
// {
//     //  std::string s(conn->receive());
// 	//  cout << "server: " << s << endl;
// 	//  MyTask b(s, 0);
// 	// // b.queryIndexTable();
// 	// // string res;

// 	// // cout << res<< endl;
//     // // conn->send(res);
// 	// //做业务逻辑的处理
// 	// pool.addTask(&b);
// }

// void onClose(const oh::TcpConnectionPtr &conn)
// {
//     printf("%s close\n", conn->toString().c_str());
// }
// int main()
// {
// 	cout << "MainThread: " << pthread_self() << endl;
   
// 	// TaskQueue tq(10);
// 	// Thread test(std::bind(test_dict, std::ref(tq)));
// 	// test.start();
// 	// test.join();
// 	// a->store_en_dict("index.dict");
// 	// MyTask b("ak",0);
// 	// b.queryIndexTable();
// 	// cout<<b._resultQue.top().get_word()<<endl;
// 	MyDict *a = MyDict::createInstance();
// 	a->init0();
// 	Threadpool pool(10,10);
// 	oh::InetAddress addr("192.168.4.16", 9999);
// 	// oh::Acceptor acceptor(createSocketFd(), addr);
// 	// acceptor.ready();

// 	// int peerfd = acceptor.accept();
// 	//oh::TcpConnection conn(peerfd);
// 	// conn.send("welcom to chat server!");
// 	TcpServer tcpserver(addr.ip(), addr.port());
//     tcpserver.setConnectionCallback(&onConnection);
// 	tcpserver.setMessageCallback(&onMessage);
// 	tcpserver.setCloseCallback(&onClose);

// 	tcpserver.start();
// 	// while (1)
// 	// {
// 	// 	string msg = conn.receive();
// 	// 	cout << "server receve: " << msg << endl;
// 	// 	conn.send(msg);
// 	// }
// 	return 0;
// }
static __thread int threadNum = 0;
int main(){
	cout << "MainThread: " << pthread_self() << endl;
    CacheManage b; 
    b.initCache(4,"../Cache/");
	SpellcorrectServer a("../conf/config");

	a.start();
	
}


 

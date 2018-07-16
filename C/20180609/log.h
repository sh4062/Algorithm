/*================================================================
*   Copyright (C) 2018 Max. All rights reserved.
*   
*   Filename   ：log.h
*   Creator    ：Max
*   Date       ：2018/06/11
*   Description：
*
================================================================*/
#include<iostream>
#include<log4cpp/Category.hh>

#include<log4cpp/Appender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
#include<log4cpp/OstreamAppender.hh>

#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>

using namespace std;

//1.实现日志文件信息在终端上显示
//2.实现日志文件信息在终端和日志文件同时显示
//3.实现回滚备份，替换掉2即可
class Mylog
{
    public:
        Mylog();
        ~Mylog();
    public:
        void error(const char * msg);
        void warn(const char * msg);
        void info(const char * msg);
        void debug(const char * msg);

        void set_priority(const char *);

    private:
        //布局
        log4cpp::PatternLayout * pLayout_cout_;
        log4cpp::PatternLayout * pLayout_file_;
        log4cpp::PatternLayout * pLayout_rollfile_;

        //依附目标文件
        log4cpp::OstreamAppender * osAppender_;
        log4cpp::FileAppender * fileAppender_;
        log4cpp::RollingFileAppender * rollfileAppender_;

        //种类
        log4cpp::Category & root_;
};

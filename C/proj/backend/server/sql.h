#ifndef __SQL_H__
#define __SQL_H__
#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
int server_login(char*argv[]);
int sql_cd(char*argv[]);
int sql_ls(char*argv[]);
int sql_gets(char*argv[]);
int sql_remove(char*argv[]);
int sql_md5(char *argv);
int sql_mkdir(char *argv[]);
int sql_puts_local(char *argv[]);
int sql_puts_user(char *argv[]);
int sql_puts_local_update(char *argv);
int sql_reg(char *argv[]);
#endif
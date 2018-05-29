#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]) {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char* server = "localhost";
  char* user = "root";
  char* pwd = "root";
  char* database = "test";
  char query[200] = "insert into person(FirstName, LastName, age)values ('zxc','asd', 5)";
  int t, r;
  conn = mysql_init(NULL);
  if(!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0)) {
    printf("ERROR connect db!%s\n",mysql_error(conn));
  } else {
    printf("Connected...\n");
  }
  t = mysql_query(conn,query);
  if(t) {
    printf("Error making query:%s", mysql_error(conn));
  } else {
    printf("insert success!\n");
  }
  mysql_close(conn);
  return 0;

}

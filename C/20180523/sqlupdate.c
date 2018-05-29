#include <mysqlgmysql.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]) {
  if(argc != 2) {
    printf("Wrong Args");
      return -1;
  }
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char* server = "localhost";
  char* user = "root";
  char* pwd = "root";
  char* database = "test";
  char query[200] = "update person set birthday = '2018-05-01' where personId =";
  int personId = atoi(argv[1]);
  sprintf(query, "%s%d", query, personId);
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
    printf("update success!\n");
  }
  mysql_close(conn);
  return 0;

}

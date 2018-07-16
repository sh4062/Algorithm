  #include "sql.h"

  int server_login(char *argv[])
  {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "select password from user where username = ";
    char qres[43];
    memset(qres, '@', sizeof(qres));

    sprintf(query, "%s'%s'", query, argv[0]);
    printf("%s\n", query);
    int t; //, r
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
      res = mysql_use_result(conn);
      if (res)
      {
        while ((row = mysql_fetch_row(res)) != NULL)
        {
          for (t = 0; t < mysql_num_fields(res); t++)
          {
            printf("%43s\n", row[t]);
            strcpy(qres, row[t]);
          }
          printf("\n");
        }
      }
      else
        return -1;
    }
    mysql_close(conn);
    if (0 == strcmp(qres, argv[1]))
    {
      printf("login successful\n");
      return 0;
    }
    else
    {
      printf("%s|||%s\n", qres, argv[1]);
      printf("login failure\n");
      return -1;
    }
  }

  int sql_ls(char *argv[])
  {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "select * from userfile where username = ";
    char returns[200] = "";
    sprintf(query, "%s'%s'", query, argv[0]);
    sprintf(query, "%s and dir = '%s'", query, argv[1]);
    sprintf(query, "%s and proposition = %s", query, argv[2]);
    printf("%s\n", query);
    int t; //, r
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
      res = mysql_use_result(conn);
      if (res)
      {
        while ((row = mysql_fetch_row(res)) != NULL)
        {
          for (t = 0; t < mysql_num_fields(res); t++)
          {
            if (row[t] && t == 2)
            {
              printf("%s\n", row[t]);
              sprintf(returns, "%s%s               ", returns, row[t]);
            }
            if (row[t] && t == 5)
            {
              printf("%s\n", row[t]);
              sprintf(returns, "%s%s\n", returns, row[t]);
            }
          }
          printf("\n");
        }
      }
      else
        return -1;
    }
    mysql_close(conn);
    argv[1] = returns;
    return 0;
  }

  int sql_cd(char *argv[])
  {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "select * from userfile where type = 'd' and username = ";
    char returns[200] = "";
    char returns2[10] = "";
    sprintf(query, "%s'%s'", query, argv[0]);
    sprintf(query, "%s and absposition = '%s'", query, argv[1]);
    printf("%s\n", query);
    int t; //, r
    int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
      res = mysql_use_result(conn);
      if (res)
      {
        while ((row = mysql_fetch_row(res)) != NULL)
        {
          for (t = 0; t < mysql_num_fields(res); t++)
          {
            if (row[t])
            {
              ret = 1;
              printf("%s\n", row[t]);
              if (t == 6)
                sprintf(returns, "%s%s", returns, row[t]);
              if (t == 1)
                sprintf(returns2, "%s%s", returns2, row[t]);
            }
          }
          printf("\n");
        }
      }
      else
        return -1;
    }
    mysql_close(conn);
    //printf("\n\n%d\n",atoi(returns2));
    if (ret == 1)
    {
      argv[0] = returns2;
      argv[1] = returns;
      return 1;
    }
    else
      return 0;
  }

  int sql_gets(char *argv[])
  {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "select b.localposition from userfile a, file b where a.md5 =b.md5 and a.type = 'f' and a.username = ";
    char returns[200] = "";
    //char returns2[10] = "";
    sprintf(query, "%s'%s'", query, argv[0]);
    sprintf(query, "%s and a.name = '%s'", query, argv[1]);
    sprintf(query, "%s and a.position = %s", query, argv[2]);
    sprintf(query, "%s and a.dir = '%s'", query, argv[3]);
    printf("%s\n", query);
    int t; //, r
    int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
      res = mysql_use_result(conn);
      if (res)
      {
        while ((row = mysql_fetch_row(res)) != NULL)
        {
          for (t = 0; t < mysql_num_fields(res); t++)
          {
            if (row[t])
            {
              ret = 1;
              printf("%s\n", row[t]);

              sprintf(returns, "%s%s", returns, row[t]);
            }
          }
          printf("\n");
        }
      }
      else
        return -1;
    }

    mysql_close(conn);
    //printf("\n\n%d\n",atoi(returns2));
    if (ret == 1)
    {

      argv[1] = returns;
      return 1;
    }
    else
      return 0;
  }

  int sql_remove(char *argv[])
  {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "update userfile,file set count=count-1 where userfile.md5 =file.md5  and userfile.username =";
    char returns[200] = "";
    sprintf(query, "%s'%s'", query, argv[0]);
    sprintf(query, "%s and userfile.name = '%s'", query, argv[1]);
    sprintf(query, "%s and userfile.position = %s", query, argv[2]);
    sprintf(query, "%s and userfile.dir = '%s'", query, argv[3]);
    printf("%s\n", query);
    int t; //, r
    int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s\n", mysql_error(conn));
      return 0;
    }
    else
    {
      printf("query success!\n");
      ret = 1;
    }
    if (ret == 0)
      return 0;
    else
      ret = 0;
    char query2[200] = "delete  from userfile  where type = 'f' and  username = ";
    sprintf(query2, "%s'%s'", query2, argv[0]);
    sprintf(query2, "%s and name = '%s'", query2, argv[1]);
    sprintf(query2, "%s and position = '%s'", query2, argv[2]);
    sprintf(query2, "%s and dir = '%s'", query2, argv[3]);
    printf("%s\n", query2);
    t = mysql_query(conn, query2);
    if (t)
    {
      printf("Error making query2:%s", mysql_error(conn));
      return 0;
    }
    else
    {
      printf("query2 success!\n");
      ret = 1;
    }
    char query3[200] = "select localposition from file  where  count = 0";
    printf("%s\n", query3);
    t = mysql_query(conn, query3);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
    }
    else
    {
      printf("query3 success!\n");
      res = mysql_use_result(conn);
      if (res)
      {
        while ((row = mysql_fetch_row(res)) != NULL)
        {
          for (t = 0; t < mysql_num_fields(res); t++)
          {
            if (row[t])
            {

              printf("%s\n", row[t]);

              sprintf(returns, "%s%s", returns, row[t]);
            }
          }
          printf("\n");
        }
      }
      // else
      //   return -1;
    }
    printf("\n%s\n", returns);
    int remove_ret = remove(returns);
    if (remove_ret == 0)
    {
      printf("Successfully %s!\n", returns);
    }
    mysql_close(conn);
    //printf("\n\n%d\n",atoi(returns2));
    if (ret == 1)
    {

      return 1;
    }
    else
      return 0;
  }

  int sql_md5(char *argv)
  {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "select localposition from file where md5 =";
    char returns[200] = "";
    sprintf(query, "%s'%s'", query, argv);

    printf("%s\n", query);
    int t; //, r
    int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
      res = mysql_use_result(conn);
      if (res)
      {
        while ((row = mysql_fetch_row(res)) != NULL)
        {
          for (t = 0; t < mysql_num_fields(res); t++)
          {
            if (row[t])
            {
              ret = 1;
              printf("%s\n", row[t]);

              sprintf(returns, "%s%s", returns, row[t]);
            }
          }
          printf("\n");
        }
      }
      else
        return -1;
    }
    //printf("\n\n%d\n",atoi(returns2));
    if (ret == 1)
    {

      return 1;
    }
    else
      return 0;
  }

  int sql_puts_local(char *argv[])
  {
    MYSQL *conn;
    //MYSQL_RES *res;
    //MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "INSERT INTO `file`(count,size,localposition,md5) VALUES ";
    sprintf(query, "%s('%s','%s','%s','%s')", query, argv[0], argv[1], argv[2], argv[3]);

    printf("%s\n", query);
    int t; //, r
    //int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
    }
    //printf("\n\n%d\n",atoi(returns2));

    return 0;
  }

  int sql_puts_user(char *argv[])
  {
    MYSQL *conn;
    //MYSQL_RES *res;
    //MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "INSERT INTO `userfile`(proposition,position,type,dir,\
  username, name ,absposition,md5) VALUES ";
    sprintf(query, "%s('%s','%s','%s','%s','%s','%s','%s','%s')", query, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[7], argv[8]);

    printf("%s\n", query);
    int t; //, r
    //int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
      return 0;
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
      return 0;
    }
    else
    {
      printf("query success!\n");
      return 1;
    }
    //printf("\n\n%d\n",atoi(returns2));
    mysql_close(conn);
    return 1;
  }

  int sql_puts_local_update(char *argv)
  {
    MYSQL *conn;
    //MYSQL_RES *res;
    //MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "update file set count=count+1 where  md5 =";
    sprintf(query, "%s'%s'", query, argv);

    printf("%s\n", query);
    int t; //, r
    int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
      ret = 0;
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
      ret = 1;
    }
    else
    {
      printf("query success!\n");
      ret = 1;
    }
    mysql_close(conn);
    return ret;
  }

  int sql_mkdir(char *argv[])
  {
    MYSQL *conn;
    //MYSQL_RES *res;
    //MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query1[200] = "INSERT INTO `file`(count,size,localposition,md5) VALUES ";
    sprintf(query1, "%s('1','0','/','%s')", query1, argv[4]);
    char query[200] = "INSERT INTO `userfile`(proposition,position,type,dir,\
  username, name ,absposition,md5) VALUES ";
    sprintf(query, "%s('%s','%d','d','%s','%s','%s','%s','%s')", query, argv[2], atoi(argv[2]) + 1, argv[3], argv[0], argv[1], argv[4], argv[4]);

    printf("%s\n", query);
    int t; //, r
    //int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
      return 0;
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query1);
    if (t)
    {
      printf("Error making query1:%s\n", mysql_error(conn));
      return 0;
    }
    else
    {
      printf("query success!\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s\n", mysql_error(conn));
      return 0;
    }
    else
    {
      printf("query success!\n");
      return 1;
    }

    //printf("\n\n%d\n",atoi(returns2));
    mysql_close(conn);
    return 1;
  }

  int sql_reg(char *argv[])
  {
    MYSQL *conn;
    //MYSQL_RES *res;
    //MYSQL_ROW row;
    char *server = "localhost";
    char *user = "root";
    char *pwd = "root";
    char *database = "fileserver";
    char query[200] = "INSERT INTO `user`(username,password) VALUES ";
    sprintf(query, "%s('%s','%s')", query, argv[0], argv[1]);

    printf("%s\n", query);
    int t; //, r
    //int ret = 0;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, pwd, database, 0, NULL, 0))
    {
      printf("ERROR connect db!%s\n", mysql_error(conn));
    }
    else
    {
      printf("Connected...\n");
    }
    t = mysql_query(conn, query);
    if (t)
    {
      printf("Error making query:%s", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
    }
    char query1[200] = "INSERT INTO `file`(count,size,localposition,md5) VALUES ";
    sprintf(query1, "%s('1','0','/','%s')", query1, argv[0]);
    printf(" %s\n", query1);
    t = mysql_query(conn, query1);
    if (t)
    {
      printf("Error making query:%s\n", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
    }

    char query2[200] = "INSERT INTO `userfile`(proposition,position,type,dir,\
  username, name ,absposition,md5) VALUES ";
    sprintf(query2, "%s('0','0','d','/','%s','%s','%s','%s')", query2, argv[0], argv[0], argv[0], argv[0]);
    printf(" %s\n", query2);
    t = mysql_query(conn, query2);
    if (t)
    {
      printf("Error making query:%s\n", mysql_error(conn));
    }
    else
    {
      printf("query success!\n");
    }

    //printf("\n\n%d\n",atoi(returns2));
    mysql_close(conn);
    return 0;
  }
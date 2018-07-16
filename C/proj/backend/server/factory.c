#include "factory.h"
//Init all elements in factory
void factory_init(factory *p, int num, int capcity)
{
  bzero(p, sizeof(factory));
  p->pth = (pthread_t *)calloc(num, sizeof(pthread_t));
  pthread_cond_init(&p->cond, NULL);
  p->pthread_num = num;
  p->que.que_capcity = capcity;
  pthread_mutex_init(&p->que.que_mutex, NULL);
}
//start thread
void factory_start(factory *p)
{
  int i;
  if (!p->start_flag)
  {
    for (i = 0; i < p->pthread_num; i++)
    {
      int r = pthread_create(p->pth + i, NULL, threadfunc, p);
      if (r != 0)
      {
        printf("ERROR CREATE THREAD!");
        exit(10);
      }
    }
    p->start_flag = 1;
  }
}

int handlecmd(char *p, int client_fd, char *username, char *pwd, int *position)
{

  //  DIR *dp = opendir("../files");
  char dir[200] = "";
  if (*position == 0)
  {
    strcpy(dir, pwd);
    // printf("\n\n\n%s\n\n\n", dirdir);
  }
  else
  {
    int cnt = 0;
    for (int i = strlen(pwd); i >= 0; i--)
    {
      cnt++;
      if (pwd[i] == '/')
        break;
    }
    //printf("%d\n", strlen(pwd) - cnt);
    int j = 0;
    for (int i = strlen(pwd) - cnt + 2; i <= strlen(pwd); i++)
    {
      dir[j++] = pwd[i];
    }
    // printf("\n\n\n%s\n\n\n", get2);
  }
  train t;
  int len;
  // printf("%s\n",p);
  if (p[0] == 'c' && p[1] == 'd' && p[2] == ' ')
  {
    int ret = 0;
    char cd[50] = "";
    int len = strlen(p);
    for (int i = 3; i < len; i++)
    {
      sprintf(cd, "%s%c", cd, p[i]);
    }
    //printf("%s\n",cd);
    if (strcmp(cd, "..") == 0)
    {
      ret = 1;
      printf("%d\n", *position);
      if (*position > 0)
      {
        (*position)--;
        int cnt = 0;
        for (int i = strlen(pwd); i >= 0; i--)
        {
          cnt++;
          if (pwd[i] == '/')
            break;
        }
        printf("%ld\n", strlen(pwd) - cnt);
        pwd[strlen(pwd) - cnt + 1] = '\0';
      }
    }
    else if (cd[0] == '/')
    {
      for (int i = 1; i < 50; i++)
      {
        cd[i - 1] = cd[i];
      }
      char cd2[200] = "";
      sprintf(cd2, "%s%s", cd2, cd);
      char *cds[3];
      cds[0] = username;
      cds[1] = cd2;
      ret = sql_cd(cds);
      if (ret == 1)
      {
        strcpy(pwd, cds[1]);
        *position = atoi(cds[0]);

        //printf("\n\n\n\n\n%s\n\n\n",cds[0]);
      }
    }
    else
    {
      if (cd[0] == '.' && cd[1] == '/')
      {
        for (int i = 2; i < 50; i++)
        {
          cd[i - 2] = cd[i];
        }
      }
      char cd2[200] = "";
      sprintf(cd2, "%s%s/%s", cd2, pwd, cd);
      char *cds[3];
      cds[0] = username;
      cds[1] = cd2;
      ret = sql_cd(cds);
      if (ret == 1)
      {
        strcpy(pwd, cds[1]);
        *position = atoi(cds[0]);

        //printf("\n\n\n\n\n%d\n\n\n", *position);
      }
    }
    if (ret == 1)
    {
      bzero(&t, sizeof(train));
      strcpy(t.buf, pwd);
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
    }
    else
    {
      bzero(&t, sizeof(train));
      strcpy(t.buf, "No such dir\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
    }
    return 0;
  }
  if (strcmp(p, "ls") == 0)
  {
    char ls1[10] = {0};
    sprintf(ls1, "%d", *position);
    char *ls[3];
    ls[0] = username;
    ls[1] = dir;
    ls[2] = ls1;
    sql_ls(ls);
    bzero(&t, sizeof(train));
    strcpy(t.buf, ls[1]);
    t.len = strlen(t.buf) + 1;
    len = send_n(client_fd, (char *)&t, 4 + t.len);
    return 0;
  }
  else if (strcmp(p, "test") == 0)
  {
    bzero(&t, sizeof(train));
    strcpy(t.buf, "test!\n");
    t.len = strlen(t.buf) + 1;
    len = send_n(client_fd, (char *)&t, 4 + t.len);
    return 0;
  }
  else if (strcmp(p, "pwd") == 0)
  {
    bzero(&t, sizeof(train));
    strcpy(t.buf, pwd);
    t.len = strlen(t.buf) + 1;
    len = send_n(client_fd, (char *)&t, 4 + t.len);
    return 0;
  }
  else if (p[0] == 'g' && p[1] == 'e' && p[2] == 't' && p[3] == 's' && p[4] == ' ')
  {
    char buf[1024] = "";
    int ret = 0;
    char get[200] = "";
    ret = recv(client_fd, &len, sizeof(int), 0);
    if (ret == 0)
    {
      perror("recv");
      return 0;
    }
    off_t filesize_truncated = 0;
    ret = recv(client_fd, &filesize_truncated, len, 0);
    printf("\n\n!!!!%ld!!!!!!!\n\n", filesize_truncated);
    if (ret == 0)
    {
      perror("recv");
      return 0;
    }
    int len = strlen(p);
    for (int i = 5; i < len; i++)
    {
      sprintf(get, "%s%c", get, p[i]);
    }
    char get1[20] = "";
    sprintf(get1, "%s%d", get1, *position);
    char *gets[4];
    gets[0] = username;
    gets[1] = get;
    gets[2] = get1;
    gets[3] = dir;

    ret = sql_gets(gets);
    if (ret == 1)
    {
      strcpy(buf, gets[1]);
      //printf("\n%s\n", buf);
      bzero(&t, sizeof(train));
      strcpy(t.buf, "Trans\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
      trans_file(client_fd, get, buf, filesize_truncated);
      // bzero(&t, sizeof(train));
      // strcpy(t.buf, "Success\n");
      // t.len = strlen(t.buf) + 1;
      // len = send_n(client_fd, (char *)&t, 4 + t.len);
      // if (len == -1)
      // {
      //   perror("send_n");
      //   return 0;
      // }
      return 0;
    }
    else
    {
      bzero(&t, sizeof(train));
      strcpy(t.buf, "No such file\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
      if (len == -1)
      {
        perror("send_n");
        return 0;
      }
    }

    return 0;
  }
  else if (p[0] == 'p' && p[1] == 'u' && p[2] == 't' && p[3] == 's' && p[4] == ' ') //puts
  {
    char md5[33] = {0};
    char buf[BUFSIZ] = {0};
    char get[200] = {0};
    int len = strlen(p);
    for (int i = 5; i < len; i++)
    {
      sprintf(get, "%s%c", get, p[i]);
    }
    printf("%s\n", get);
    int ret = recv(client_fd, &len, sizeof(int), 0);
    if (ret == 0)
    {
      perror("recv");
      return 0;
    }
    ret = recv(client_fd, md5, len, 0);
    if (ret == 0)
    {
      perror("recv");
      return 0;
    }
    printf("%s\n", md5);
    ret = sql_md5(md5);
    if (ret == 0) //没有这个md5 上传文件并添加sqlo
    {
      bzero(&t, sizeof(train));
      strcpy(t.buf, "uploading\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
      if (len == -1)
      {
        perror("send_n");
        return 0;
      }

      printf("Start uploading------\n");
      // receive file name
      ret = recv(client_fd, &len, sizeof(int), 0);
      if (ret == 0)
      {
        perror("recv name");
        return 0;
      }
      ret = recv(client_fd, buf, len, 0);
      if (ret == 0)
      {
        perror("recv name");
        return 0;
      }
      // receive file length
      ret = recv(client_fd, &len, sizeof(int), 0);
      if (ret == 0)
      {
        perror("recv length");
        return 0;
      }
      off_t file_size;
      ret = recv(client_fd, &file_size, len, 0);
      if (ret == 0)
      {
        perror("rec length");
        return 0;
      }
      //
      char *puts[9];
      
      char puts0[10] = "";
      char num[9] = "";
      sprintf(puts0, "%s%d", puts0, 1);
      sprintf(num, "%s%ld", num, file_size);
      puts[0] = puts0;
      puts[1] = num;
      
      puts[3] = md5;
      //
      // printf("receive %ld\n", file_size);
      //receive file
      bzero(buf, sizeof(buf));
      sprintf(buf, "../files/%s", md5);
      //printf("!!!!%s!!!!!!!1\n",buf);
      //保存路径

      int fd = open(buf, O_RDWR | O_CREAT, 0666);
      if (fd == -1)
      {
        perror("file open");
        return -1;
      }
      time_t before, now;
      now = time(NULL);
      before = now;
      float real_size = 0;

      //receive file
      while (1)
      {
        ret = recv_n(client_fd, (char *)&len, sizeof(int));
        if (ret == -1)
        {
          perror("server recv");
          return -1;
        }
        //printf("receive %d\n", len);
        if (len > 0)
        {
          ret = recv_n(client_fd, buf, len);
          if (ret == -1)
          {
            perror("server recv");
            return -1;
          }
          write(fd, buf, len);
          real_size = real_size + len;
          if (real_size == file_size)
          {
            printf("\r100.00%s\n", "%");
            printf("file recv success!\n");
            break;
          }
          now = time(NULL);
          if (now - before >= 1)
          {
            printf("\r%5.2f%s", real_size / file_size * 100, "%");
            fflush(stdout);
            before = now;
          }
        }
      }

      printf("over!\n");
      close(fd);
      bzero(&t, sizeof(train));
      strcpy(t.buf, "Puts success!\n");
      t.len = strlen(t.buf);
      len = send_n(client_fd, (char *)&t, 4 + t.len);
      char puts1[200] ="";

      sprintf(puts1, "../files/%s", md5);
      puts[2] = puts1;
      // printf("!!!!%s!!!!!!!1\n", puts1);
      // printf("!!!!%s!!!!!!!1\n", puts[2]);
      sql_puts_local(puts);
      char num1[9] = "";
      char num2[9] = "";
      //char num3[9] = "";
      sprintf(num, "%d", *position);
      sprintf(num1, "%d", *position);
      puts[0] = num;
      puts[1] = num1;
      sprintf(num2, "%s", "f");
      puts[2] = num2;
      puts[3] = username;
      puts[4] = dir;
      puts[5] = get;
      //  printf("!!!!%s!!!!!!!1\n", get);
      // sprintf(num3,"%ld", file_size);
      // puts[6]=num3;
      bzero(buf, sizeof(buf));
      printf("%s\n", buf);
      sprintf(buf, "%s%s/%s",buf, pwd, get);
      puts[7] = buf;
      printf("!!!!%s!!!!!!!1\n", puts[7]);
      puts[8] = md5;
      ret = sql_puts_user(puts);
      printf("sql_puts_local\n");
      if (ret == 1)
      {

        bzero(&t, sizeof(train));
        strcpy(t.buf, "Puts success!\n");
        t.len = strlen(t.buf) + 1;
        len = send_n(client_fd, (char *)&t, 4 + t.len);
      }
      else
      {
        bzero(&t, sizeof(train));
        strcpy(t.buf, "Puts failure!\n");
        t.len = strlen(t.buf) + 1;
        len = send_n(client_fd, (char *)&t, 4 + t.len);
      }
    }
    else //有这个md5 sql添加count和userfile
    {    //

      bzero(&t, sizeof(train));
      strcpy(t.buf, "Existed");
      printf("Existed\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);

      char num[9] = "";
      char num1[9] = "";
      char num2[9] = "";
      //char num3[9] = "";
      sprintf(num, "%d", *position);
      sprintf(num1, "%d", *position);
      char *puts[9];
      puts[0] = num;
      puts[1] = num1;
      sprintf(num2, "%s", "f");
      puts[2] = num2;
      puts[3] = username;
      puts[4] = dir;
      puts[5] = get;
      // sprintf(num3,"%ld", );
      //puts[6]=num3;
      bzero(buf, sizeof(buf));
      sprintf(buf, "%s/%s", pwd, get);
      puts[7] = buf;
      puts[8] = md5;
      ret = sql_puts_user(puts);
      if (ret == 1)
      {
        sql_puts_local_update(md5);
        printf("Existed\n");
        bzero(&t, sizeof(train));
        strcpy(t.buf, "Puts success!\n");
        t.len = strlen(t.buf) + 1;
        len = send_n(client_fd, (char *)&t, 4 + t.len);
      }
      else
      {
        bzero(&t, sizeof(train));
        strcpy(t.buf, "Puts failure!\n");
        t.len = strlen(t.buf) + 1;
        len = send_n(client_fd, (char *)&t, 4 + t.len);
      }
    }
    return 0;
  }
  else if (p[0] == 'r' && p[1] == 'e' && p[2] == 'm' && p[3] == 'o' && p[4] == 'v' && p[5] == 'e' && p[6] == ' ')
  {
    //char buf[1024] = "";
    int ret = 0;
    char get[200] = "";
    int len = strlen(p);
    for (int i = 7; i < len; i++)
    {
      sprintf(get, "%s%c", get, p[i]);
    }
    char get1[20] = "";
    sprintf(get1, "%s%d", get1, *position);
    char *gets[4];
    gets[0] = username;
    gets[1] = get;
    gets[2] = get1;
    gets[3] = dir;

    ret = sql_remove(gets);
    if (ret == 1)
    {

      bzero(&t, sizeof(train));
      strcpy(t.buf, "Remove Success\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
    }
    else
    {
      bzero(&t, sizeof(train));
      strcpy(t.buf, "No such file\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
    }

    return 0;
  }
  else if (p[0] == 'm' && p[1] == 'k' && p[2] == 'd' && p[3] == 'i' && p[4] == 'r' && p[5] == ' ')
  {
    //char buf[1024] = "";
    int ret = 0;
    char get[200] = "";
    int len = strlen(p);
    for (int i = 6; i < len; i++)
    {
      sprintf(get, "%s%c", get, p[i]);
    }
    char get1[20] = "";
    sprintf(get1, "%s%d", get1, *position);
    char *gets[5];
    char get4[200] = "";
    sprintf(get4,"%s/%s",pwd,get);
    gets[0] = username;
    gets[1] = get;
    gets[2] = get1;
    gets[3] = dir;
    gets[4] = get4;
    ret = sql_mkdir(gets);
    if (ret == 1)
    {

      bzero(&t, sizeof(train));
      strcpy(t.buf, "mkdir Success\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
    }
    else
    {
      bzero(&t, sizeof(train));
      strcpy(t.buf, "mkdir failure\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(client_fd, (char *)&t, 4 + t.len);
    }

    return 0;
  }
  else
    return 0;
}

//thread
void *threadfunc(void *p)
{
  int len;
  char buf[BUFSIZ];
  char buf2[BUFSIZ];
  int try
    = 0;
  int ret;
  train t;
  factory *pf = (factory *)p;
  pque_t pq = &pf->que;
  pnode_t pcur;
  pthread_cleanup_push((void *)pthread_mutex_unlock, (void *)&pq->que_mutex);
  char user[255] = {0};
  char pwd[255] = {0};
  FILE *log = fopen("../log/log", "r+");
  if (log == NULL)
  {
    perror("Log ERROR");
    return NULL;
  }

  time_t rawtime;
  struct tm *info;

  while (1)
  {
    pthread_mutex_lock(&pq->que_mutex);
    if (!pq->que_size)
    {
      pthread_cond_wait(&pf->cond, &pq->que_mutex);
    }
    que_get(pq, &pcur);
    pthread_mutex_unlock(&pq->que_mutex);
    printf("Thread handle!\n");

    time(&rawtime);
    info = localtime(&rawtime);
    fseek(log, 0, SEEK_END);
    fprintf(log, "Thread handle! %s\n", asctime(info));
    fseek(log, 0, SEEK_END);
    while (1)
    {
      char *login_[2];
      bzero(buf, sizeof(buf));
      bzero(buf2, sizeof(buf2));
      ret = recv(pcur->new_fd, &len, sizeof(int), 0);
      if (ret == 0)
      {
        printf("Client Disconnected\n");
        time(&rawtime);
        info = localtime(&rawtime);
        fprintf(log, "Client Disconnected %s\n", asctime(info));
        fseek(log, 0, SEEK_END);
        goto exitP;
      }
      recv(pcur->new_fd, buf, len, 0);
      if (strcmp(buf, "reg") == 0)
      {
        bzero(&t, sizeof(train));
        strcpy(t.buf, "Sign Up\n");
        t.len = strlen(t.buf) + 1;
        len = send_n(pcur->new_fd, (char *)&t, 4 + t.len);

        ret = recv(pcur->new_fd, &len, sizeof(int), 0);
        if (ret == 0)
        {
          printf("Client Disconnected\n");
          time(&rawtime);
          info = localtime(&rawtime);
          fprintf(log, "Client Disconnected %s\n", asctime(info));
          fseek(log, 0, SEEK_END);
          goto exitP;
        }
        recv(pcur->new_fd, buf, len, 0);

        ret = recv(pcur->new_fd, &len, sizeof(int), 0);
        if (ret == 0)
        {
          printf("Client Disconnected\n");
          time(&rawtime);
          info = localtime(&rawtime);
          fprintf(log, "Client Disconnected %s\n", asctime(info));
          goto exitP;
        }
        recv(pcur->new_fd, buf2, len, 0);
        login_[0] = buf;
        login_[1] = buf2;
        sql_reg(login_);
        continue;
      }
      ret = recv(pcur->new_fd, &len, sizeof(int), 0);
      if (ret == 0)
      {
        printf("Client Disconnected\n");
        time(&rawtime);
        info = localtime(&rawtime);
        fprintf(log, "Client Disconnected %s\n", asctime(info));
        goto exitP;
      }
      recv(pcur->new_fd, buf2, len, 0);
      login_[0] = buf;
      login_[1] = buf2;
      printf("%s %s\n", buf, buf2);
      int login_ret = server_login(login_);
      printf("%d!\n", try);
      if (login_ret == 0)
      {
        printf("Login!\n");
        time(&rawtime);
        info = localtime(&rawtime);
        fprintf(log, "Login Success! username = %s %s\n", buf, asctime(info));
        fseek(log, 0, SEEK_END);
        bzero(&t, sizeof(train));
        strcpy(t.buf, "Login Success!\n");
        t.len = strlen(t.buf) + 1;
        len = send_n(pcur->new_fd, (char *)&t, 4 + t.len);
        bzero(user, sizeof(user));
        strcpy(user, buf);
        bzero(pwd, sizeof(pwd));
        strcpy(pwd, buf);
        break;
      }
      if (login_ret == -1)
      {
        try
          ++;
        if (try == 5)
          break;
        continue;
      }
    }
    if (try == 5)
    {
      bzero(&t, sizeof(train));

      strcpy(t.buf, "Too many try!\n");
      t.len = strlen(t.buf) + 1;
      len = send_n(pcur->new_fd, (char *)&t, 4 + t.len);
      close(pcur->new_fd);
      break;
    }
    sprintf(pwd, "%s", pwd);
    int position = 0;
    while (1)
    {

      bzero(buf, sizeof(buf));
      ret = recv(pcur->new_fd, &len, sizeof(int), 0);
      if (ret == 0)
      {
        printf("Client Disconnected\n");
        time(&rawtime);
        info = localtime(&rawtime);
        fprintf(log, "Client Disconnected %s\n", asctime(info));
        fseek(log, 0, SEEK_END);
        goto exitP;
      }
      recv(pcur->new_fd, buf, len, 0);

      time(&rawtime);
      info = localtime(&rawtime);
      fprintf(log, "cmd: %s %s\n", buf, asctime(info));
      fseek(log, 0, SEEK_END);
      char dir[25] = "";
      strcpy(dir, pwd);
      handlecmd(buf, pcur->new_fd, user, pwd, &position);
    }
    //printf("Trans\n");
    //trans_file(pcur->new_fd)re;
  }

exitP:
  close(pcur->new_fd);
  free(pcur);
  fclose(log);
  pthread_cleanup_pop(0);
  return NULL;
}

void factory_exit(factory *p)
{
  int i;
  void *status;

  //pque_t pq = &p->que;
  printf("Exiting!\n");
  for (i = 0; i < p->pthread_num; i++)
  {
    pthread_cancel(*(p->pth + i));
    printf("%ld\n", *(p->pth + i));
    pthread_join(*(p->pth + i), &status);
    printf("joined!\n");
  }
  p->start_flag = 0;
  printf("Exited!\n");
  return;
}
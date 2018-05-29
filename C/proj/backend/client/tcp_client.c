#include "fun.h"
#include <crypt.h>
int send_n(int sfd, char *p, int len)
{
  int ret;
  int total = 0;
  while (total < len)
  {
    ret = send(sfd, p + total, len - total, 0);
    if (ret == 0)
    {
      perror("client send");
      return -1;
    }
    total = total + ret;
  }
  return 0;
}

int recv_n(int sfd, char *p, int len)
{
  int ret;
  int total = 0;
  while (total < len)
  {
    ret = recv(sfd, p + total, len - total, 0);
    if (ret == 0)
    {
      perror("client recv");
      return -1;
    }
    total = total + ret;
  }
  return 0;
}

void trans_file(int sfd, char *FILENAME)
{
  train t;
  t.len = strlen(FILENAME);
  strcpy(t.buf, FILENAME);
  //把文件名发送给对端
  send(sfd, &t, 4 + t.len, 0);
  struct stat filesize;
  stat(FILENAME, &filesize);

  memcpy(t.buf, &filesize.st_size, sizeof(off_t));
  t.len = sizeof(off_t);
  send_n(sfd, (char *)&t, 4 + t.len);
  	printf("aaaaa\n");
  int fd;
  fd = open(FILENAME, O_RDWR);
  while ((t.len = read(fd, t.buf, sizeof(t.buf))) > 0)
  {
    send_n(sfd, (char *)&t, 4 + t.len);
  }
  	printf("bbbbb\n");
  t.len = 0;
  //send(sfd, &t, 4 + t.len, 0); //开一趟空火车
}

int main(int argc, char **argv)
{
  int client_sockfd;
  int server_sockid;
  int len;
  struct sockaddr_in remote_addr;
  char buf[BUFSIZ];
  char buf2[BUFSIZ];
  memset(&remote_addr, 0, sizeof(remote_addr));         //数据初始化--清零
  remote_addr.sin_family = AF_INET;                     //设置为IP通信
  remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //服务器IP地址
  remote_addr.sin_port = htons(7777);                   //服务器端口号

  if ((client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    perror("socket error");
    return 1;
  }
  if (connect(client_sockfd, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) < 0)
  {
    perror("connect error");
    return -1;
  }
  printf("connected to server\n");
  //len=recv(client_sockfd,buf,BUFSIZ,0);//接收服务器端信息
  //buf[len]='\0';
  //printf("%s",buf); //打印服务器端信息
  fd_set fdset;
  int login = 0;
  while (1)
  {
    FD_ZERO(&fdset);
    FD_SET(STDIN_FILENO, &fdset);
    FD_SET(client_sockfd, &fdset);
    if (login == 0)
      printf("username\n");
    else
      printf("\ninput cmd\n");
    int ret = select(client_sockfd + 1, &fdset, NULL, NULL, NULL);
    if (ret > 0)
    {
      if (FD_ISSET(client_sockfd, &fdset))
      {
        bzero(buf, sizeof(buf));
        //ret = recv(client_sockfd, buf, sizeof(buf),0);
        recv(client_sockfd, &len, sizeof(int), 0);
        recv(client_sockfd, buf, len, 0);
        // if(ret == 0){
        //   printf("ByeBye\n");
        //   break;
        // }

        if (strcmp(buf, "Login Success!\n") == 0)
        {
          printf("!!!");
          login = 1;
        }
        if (strcmp(buf, "Trans\n") == 0)
        {
          printf("Received: %s\n", buf);
          char buf[1111] = {0};
          int len;
          // receive file name
          ret = recv(client_sockfd, &len, sizeof(int), 0);
          if (ret == 0)
          {
            perror("client recv");
            return -1;
          }
          ret = recv(client_sockfd, buf, len, 0);
          if (ret == 0)
          {
            perror("client recv");
            return -1;
          }
          // receive file length
          ret = recv(client_sockfd, &len, sizeof(int), 0);
          if (ret == 0)
          {
            perror("client recv");
            return -1;
          }
          off_t file_size;
          ret = recv(client_sockfd, &file_size, len, 0);
          if (ret == 0)
          {
            perror("client recv");
            return -1;
          }
          printf("receive %ld\n", file_size);
          //receive file
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
            ret = recv_n(client_sockfd, (char *)&len, sizeof(int));
            if (ret == -1)
            {
              perror("client recv_n");
              return -1;
            }
            //printf("receive %d\n", len);
            if (len > 0)
            {
              ret = recv_n(client_sockfd, buf, len);
              if (ret == -1)
              {
                perror("client recv_n");
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
          continue;
        }
        // printf("Received:%d %ld %s \n", len,strlen(buf), buf );
        printf("Received: \n%s", buf);
      }
      if (FD_ISSET(0, &fdset))
      {
        if (login == 0)
        {
          char *cpwd = (char *)calloc(1, 44);
          while (1)
          {

            bzero(buf, sizeof(buf));
            bzero(buf2, sizeof(buf2));
            ret = read(STDIN_FILENO, buf, sizeof(buf) - 1);
            if (ret == 0)
            {
              printf("Bye\n");
              break;
            }
            printf("password\n");
            ret = read(STDIN_FILENO, buf2, sizeof(buf2) - 1);
            if (ret == 0)
            {
              printf("Bye\n");
              break;
            }

            cpwd = crypt(buf2, "$5$elephant");
            if (strlen(cpwd) == 0 || strlen(buf) == 0)
            {
              printf("username\n");
              continue;
            }
            else
              break;
          }
          // if(!strcmp(buf,"quit")){
          //   break;
          // }
          train t;
          bzero(&t, sizeof(train));
          t.len = strlen(buf) - 1;
          strcpy(t.buf, buf);
          len = send_n(client_sockfd, (char *)&t, 4 + t.len);
          bzero(&t, sizeof(train));
          t.len = strlen(cpwd);
          strcpy(t.buf, cpwd);
          len = send_n(client_sockfd, (char *)&t, 4 + t.len);
          //  len=recv(client_sockfd,buf,BUFSIZ,0);
          //  buf[len] = '\0';
          //  printf("reveived: %s\n",buf);
        }
        else
        {
          // printf("input cmd\n");
          bzero(buf, sizeof(buf));
          ret = read(STDIN_FILENO, buf, sizeof(buf) - 1);
          if (ret == 0)
          {
            printf("Bye\n");
            break;
          }
          if (buf[0] == 'p' && buf[1] == 'u' && buf[2] == 't' && buf[3] == 's' && buf[4] == ' ')
          {
            char get[200] = "";
            int len = strlen(buf);
            for (int i = 5; i < len - 1; i++)
            {
              sprintf(get, "%s%c", get, buf[i]);
            }
            // printf("%s\n", get);
            // sprintf(get,"%s",get);
            printf("%s\n", get);
            FILE *test = fopen(get, "r+");
            if (test == NULL)
            {
              printf("No such file\n");
              continue;
            }
            char digest[33];
            Compute_file_md5(get, digest);
            fclose(test);
            printf("%s\n",digest);
            train t;
            bzero(&t, sizeof(train));
            t.len = strlen(buf) - 1;
            strcpy(t.buf, buf);
            len = send_n(client_sockfd, (char *)&t, 4 + t.len);
            bzero(&t, sizeof(train));
            t.len = strlen(digest);
            strcpy(t.buf, digest);
            len = send_n(client_sockfd, (char *)&t, 4 + t.len);
            bzero(buf,sizeof(buf));
            recv(client_sockfd, &len, sizeof(int), 0);
            recv(client_sockfd, buf, len, 0);
            if(strcmp(buf,"Existed")==0)
            
            // else
            printf("Puts success\n");
            else{
            trans_file(client_sockfd,get);
            }
          }
          else
          {
            //printf("send cmd\n");
            train t;
            bzero(&t, sizeof(train));
            t.len = strlen(buf) - 1;
            strcpy(t.buf, buf);
            len = send_n(client_sockfd, (char *)&t, 4 + t.len);
          }
        }
      }
    }
  } /*  */
  close(client_sockfd);
  return 0;
}

#include "fun.h"

 struct msg
{
    long client_pid;
    char my_data[512];
} ;

void handleS(int signo, siginfo_t *p, void *p1)
{
    printf("\nCleaning------------------------------------\n");
    key_t keyb = ftok("./b", 2); //1. 写入端先用 ftok 函数获得 key
    if (keyb == -1)
    {
        perror("ftok");
        exit(-1);
    }
    int msgid = msgget(keyb, 0600 | IPC_EXCL); //获得消息队列
    if (msgid == -1)
    {
        perror("b1 msgid");
        exit(1);
    }
    if (msgctl(msgid,IPC_RMID,NULL) == -1) //5. 关闭共享内存段
    {
        perror("msgctl handleS");
        exit(10);
    }
    printf("Bye\n");
    exit(0);
}

void msgsend( struct msg buf)
{   key_t keyb = ftok("./b", 2); //1. 读入端用 ftok 函数获得 key
    if (keyb == -1)
    {
        perror("ftok");
        exit(-1);
    }
    int msgid = msgget(keyb, 0666 | IPC_CREAT); //获取消息队列
    if (msgid == -1)
    {
        perror("b msgget");
        exit(1);
    }
    //printf("!!!!!!send %s\n",buf.my_data);
    msgsnd(msgid, &buf, sizeof(buf.my_data), 0);    //发送信号
    //memset(&buf, 0, sizeof(buf));                  //清空结构体
    // msgrcv(msgid, &msg, sizeof(msg.buffer), 2, 0); //接收信号
    // fprintf(stdout, "Client receive:%s\n", msg.buffer);
}
int main()
{

    int fdw = open("./pipe1", O_WRONLY);
    int fdr = open("./pipe2", O_RDONLY);
    if ((-1 == fdr) || (-1 == fdw))
    {

        perror("open");

        exit(-1);
    }
   
    printf("R %d W %d\n", fdr, fdw);
    char buf[128] = {0};
    int ret = 0;
    fd_set redset;
    struct sigaction st;
    st.sa_sigaction = handleS;
    st.sa_flags = SA_SIGINFO;
    int res = sigaction(SIGINT, &st, NULL);
     struct msg my_msg;
    while (1)
    {
        FD_ZERO(&redset);
        FD_SET(0, &redset);
        FD_SET(fdr, &redset);
        ret = select(fdr + 1, &redset, NULL, NULL, NULL);
        if (ret > 0)
        {
            if (FD_ISSET(fdr, &redset))
            {
                memset(buf, 0, sizeof(buf));
                ret = read(fdr, buf, sizeof(buf));
                if (ret == 0)
                {
                    printf("Bye");
                    break;
                }
                //printf("???%s\n", buf);
                memset(&my_msg,0,sizeof(my_msg));
                strcpy(my_msg.my_data,buf);
                my_msg.client_pid=1;
                msgsend(my_msg);
            }
            if (FD_ISSET(0, &redset))
            {
                memset(buf, 0, sizeof(buf));
                ret = read(0, buf, sizeof(buf));

                if (ret == 0)
                {
                    printf("Bye");
                    break;
                }
                ret = write(fdw, buf, strlen(buf) - 1);
            }
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}

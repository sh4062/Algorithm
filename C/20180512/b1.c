#include "fun.h"

 struct msgs
{
    long client_pid;
    char my_data[512];
} ;
int main()
{   key_t keyb = ftok("./b", 2); //1. 读入端用 ftok 函数获得 key
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
    struct msgs msg ;
    memset(&msg, 0, sizeof(struct msgs));
    while (1)
    {
        msgrcv(msgid, &msg, sizeof(msg.my_data), 1, 0); //接收消息
        //fprintf(stdout, "Server Receive:%s\n", msg.my_data);
        printf("%s\n",msg.my_data);
     
    }
    exit(0);
}
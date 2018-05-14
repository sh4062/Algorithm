#include "fun.h"

typedef struct tagmag
{
    int client_pid;
    char my_data[512];
} MSG;

void semunlock()
{
    key_t key_s = ftok("./sem", 1); //1. 写入端先用 ftok 函数获得 key
    if (key_s == -1)
    {
        perror("ftok semaphore");
        exit(-1);
    }
    int semid = semget(key_s, 1, IPC_CREAT | 0644);
    if (-1 == semid)
    {
        perror("keys semid");
        exit(10);
    }
    int ret = semctl(semid, 0, SETVAL, 1);
    if (-1 == ret)
    {
        perror("keys semctl");
        exit(10);
    }
    struct sembuf semp, semv; 
    semp.sem_num = 0;
    semp.sem_op = -1;
    semp.sem_flg = SEM_UNDO;
    semv.sem_num = 0;
    semv.sem_op = 1;
    semv.sem_flg = SEM_UNDO;
    semop(semid, &semv, 1);
}
int main()
{

    key_t key = ftok("a", 1); //1. 读入端用 ftok 函数获得 key
    if (key == -1)
    {
        perror("ftok");
        exit(-1);
    }
    int shmid = shmget(key, 4096, 0600 | IPC_EXCL); //2. 读入端用 shmget 函数打开共享内存段
    if (shmid == -1)
    {
        perror("shmget");
        exit(-1);
    }
    MSG *pMap = (MSG *)shmat(shmid, NULL, 0); //3. 获得共享内存段的首地址
    while (1)
    {   
        if (pMap->client_pid == 1)
        {
            semunlock();
            printf("%s\n", pMap->my_data); //4. 读取共享内存段中的内容
            pMap->client_pid = 0;
        }
    }
}
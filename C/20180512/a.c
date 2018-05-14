#include "fun.h"

typedef struct tagmag
{
    int client_pid;
    char my_data[512];
} MSG;

void shm(MSG buf)
{
    key_t key = ftok("./a", 1); //1. 写入端先用 ftok 函数获得 key
    if (key == -1)
    {
        perror("ftok");
        exit(-1);
    }
    int shmid = shmget(key, 4096, IPC_CREAT); //2. 写入端用 shmget 函数创建一共享内存段
    // MSG* msg = (MSG *)malloc(sizeof(MSG));
    // msg = (MSG *)shmat(shmid , NULL , 0);

    if (shmid == -1)
    {
        perror("shmget");
        exit(-1);
    }
    MSG *pMap = (MSG *)shmat(shmid, NULL, 0); //3. 获得共享内存段的首地址
    memset(pMap, 0, 4096);
    memcpy(pMap, &buf, sizeof(MSG)); //4. 往共享内存段中写入内容
}

union semun //必须重写这个共用体
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void semlock()
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
    semop(semid, &semp, 1);
}

void handleS(int signo, siginfo_t *p, void *p1)
{
    printf("\nCleaning------------------------------------\n");
    key_t key = ftok("./a", 1); //1. 写入端先用 ftok 函数获得 key
    if (key == -1)
    {
        perror("ftok");
        exit(-1);
    }
    int shmid = shmget(key, 4096, IPC_CREAT);
    MSG *pMap = (MSG *)shmat(shmid, NULL, 0);
    printf("Bye");
    if (shmdt(pMap) == -1) //5. 关闭共享内存段
    {
        perror("shmdt handleS");
        exit(10);
    }
    printf("Bye\n");
    exit(0);
}

int main()
{

    int fdr, fdw;
    fdr = open("./pipe1", O_RDONLY);
    fdw = open("./pipe2", O_WRONLY);
    if ((-1 == fdr) || (-1 == fdw))
    {

        perror("open");

        exit(-1);
    }
    printf("R %d W %d\n", fdr, fdw);
    char buf[512] = {0};
    int ret = 0;
    fd_set redset;
    MSG my_msg;
    struct sigaction st;
    st.sa_sigaction = handleS;
    st.sa_flags = SA_SIGINFO;
    int res = sigaction(SIGINT, &st, NULL);
    if (res == -1)
    {
        perror("SIG a");
        return -1;
    }
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
                strcpy(my_msg.my_data, buf);
                my_msg.client_pid = 1;
                //printf(":%s\n", buf);
                semlock();

                shm(my_msg);
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
                write(fdw, buf, strlen(buf) - 1);
            }
        }
    }
    close(fdr);
    close(fdw);
    return 0;
}

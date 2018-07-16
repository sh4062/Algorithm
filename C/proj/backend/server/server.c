#include "server.h"
factory f;


void handleS(int signo, siginfo_t * p, void *p1){
	printf("handle Sig!\n");
	factory_exit(&f);
	exit(0);
}

int main()
{
    FILE *conf = fopen("../conf/server.conf", "r+");
    if (conf == NULL)
    {
        perror("open conf");
        return -1;
    }
    char server_ip[25];
    char server_port[10];
    fscanf(conf, "%s%s", server_ip, server_port);
    printf("%s\n%s\n", server_ip, server_port);
    
    factory_init(&f, MaxPthread, PthreadCap);
    factory_start(&f);
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("server socket");
        return -1;
    }
    int reuse = 1;
    // int opt_val = 1;

    int ret = setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(int));
    if (ret == -1)
    {
        perror("socketopt\n");
        return -1;
    }
    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(server_port));
    server.sin_addr.s_addr = inet_addr(server_ip);
    ret = bind(server_fd, (struct sockaddr *)&server, sizeof(struct sockaddr));
    if (ret == -1)
    {
        perror("bind");
        return -1;
    }
    ret = listen(server_fd, 100);

    if (ret == -1)
    {
        perror("listen");
        return -1;
    }
    int client_fd;
    pnode_t pnew;
    pque_t pq = &f.que;
    printf("waiting\n");
    struct sockaddr_in client;
    socklen_t len;
    // struct epoll_event event;
    // struct epoll_event events[10];
    // int epfd;
    // epfd = epoll_create(10);
    // fd_Setnonblocking(epfd);
    // memset(&event, 0, sizeof(event));
    // event.data.fd = server_fd;
    // event.events = EPOLLIN | EPOLLET;
    // epoll_ctl(epfd, EPOLL_CTL_ADD, server_fd, &event);
    // int nfds, i;
    char buf[BUFSIZ];
    char buf2[BUFSIZ];
    FILE *log = fopen("../log/log", "r+");
    if (log == NULL)
    {
        perror("Log ERROR");
        return -1;
    }
    fseek(log, 0, SEEK_END);
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    //信号
    struct sigaction act;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    // struct sigaction st;
    act.sa_sigaction = handleS;
    act.sa_flags = SA_SIGINFO | SA_NODEFER;
    ret = sigaction(SIGINT, &act, NULL);
    if (ret == -1)
    {
        perror("SIG\n");
        return -1;
    }
    //sigaction(SIGQUIT, &act, NULL);
    while (1)
    {
        // nfds = epoll_wait(epfd, events, 10, 500);
        // for (i = 0; i < nfds; ++i)
        // {
        //     if (events[i].data.fd == server_fd && events[i].events == EPOLLIN)
        //     {
        char logger[1024] = "";
        len = sizeof(struct sockaddr);
        client_fd = accept(server_fd, (struct sockaddr *)&client, &len);
        printf("@client ip=%s,port=%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        sprintf(logger, "%s@client ip=%s,port=%d ", logger, inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        //len = send(client_fd, "Welcome!\n", 21, 0);
        train t;
        bzero(&t, sizeof(train));

        strcpy(t.buf, "Welcome!\n");
        t.len = strlen(t.buf) + 1;
        len = send_n(client_fd, (char *)&t, 4 + t.len);
        time(&rawtime);

        info = localtime(&rawtime);
        printf("：%s", asctime(info));
        sprintf(logger, "%s：%s", logger, asctime(info));
        printf("logger:::%s", logger);
        fprintf(log, "%s", logger);
        // fclose(log);

        // fd_Setnonblocking(client_fd);
        // event.data.fd = client_fd;
        // event.events = EPOLLIN | EPOLLET;
        // epoll_ctl(epfd, EPOLL_CTL_ADD, client_fd, &event);
        // }
        // else if (events[i].events == EPOLLIN && events[i].data.fd == client_fd)
        // {
        // if ((client_fd = events[i].data.fd) < 0)
        //     continue;

        pnew = (pnode_t)calloc(1, sizeof(node_t));
        pnew->new_fd = client_fd;
        pthread_mutex_lock(&pq->que_mutex);
        que_insert(pq, pnew);
        pthread_mutex_unlock(&pq->que_mutex);
        pthread_cond_signal(&f.cond);

        // }
        //    {
        //      /*
        //   rdata=(struct user_data *)events[i].data.ptr;
        //      sockfd = rdata->fd;
        //      write(sockfd, rdata->line, rdata->n_size);
        //      delete rdata;
        //      //设置用于读操作的文件描述符
        //      ev.data.fd=sockfd;
        //      //设置用于注测的读操作事件
        //    ev.events=EPOLLIN|EPOLLET;
        //      //修改sockfd上要处理的事件为EPOLIN
        //    epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
        //  */
        //    }
        // }
    }
    fclose(log);
}

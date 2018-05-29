objects : server.o client.o
server.o: tcp_epoll_server.c fun.h
	cc   tcp_epoll_server.c -o server.o
client.o: tcp_client.c fun.h
	cc  tcp_client.c -o client.o
clean:
	rm *.o

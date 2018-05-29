main:tcp_client.o tcp_server.o Makefile
tcp_client.o: tcp_client.c fun.h
	gcc tcp_client.c -o tcp_client.o
tcp_server.o: tcp_server.c fun.h
	gcc tcp_server.c -o tcp_server.o

clean:
	rm *.o

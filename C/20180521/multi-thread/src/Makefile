SOURCES:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SOURCES))
ELF:=server
CC:=gcc
CFLAGS:=-Wall -I ../include
$(ELF):$(OBJS)
	gcc $^ -o $@ -pthread
clean:
	rm -r $(OBJS) $(ELF)

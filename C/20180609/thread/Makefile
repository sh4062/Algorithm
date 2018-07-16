

#================================================================
#   Copyright (C) 2018 Max. All rights reserved.
#   
#   Filename   ：Makefile
#   Creator    ：Max
#   Date       ：2018/06/11
#   Description：
#
#================================================================

SOURCES:=$(wildcard *.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(SOURCES))
ELF:=testthread
CC:=g++
CFLAGS:=-Wall -I ../include
$(ELF):$(OBJS)
	g++ $^ -o $@ -std=c++0x -pthread
clean:
	rm -r $(OBJS) $(ELF)



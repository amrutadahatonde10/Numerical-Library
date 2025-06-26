# Makefile for 8 Queens Problem

CC = g++
CCFLAGS =-C -I.
DEPS=Board.h Queen.h 
TARGET=queen
OBJS=main.o \
		Board.o \
    	Queen.o

%.o: %.cpp $(DEPS)
    $(CC) -o $@ $(CCFLAGS) $<

$(TARGET): $(OBJS)
    $(CC) -o $@ $^

clean:
    \rm *.o *~
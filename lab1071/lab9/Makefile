# Makefile for Lab 9
CC = g++
CFLAGS = -g -Wall

OBJS= matrix.o\
      main.o

INCS=matrix.h

lab9: ${OBJS}
	@echo
	@echo Linking $@
	g++ -o $@ -Wall -g ${OBJS} -lm

${OBJS}: ${INCS} Makefile

clean:
	rm -f *.o lab9 

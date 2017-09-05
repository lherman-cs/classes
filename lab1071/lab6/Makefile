# Makefile for Lab 6
CC = gcc
CFLAGS = -g -Wall

OBJS= list.o    \
      listtest.o      

INCS=   list.h        

lab6: ${OBJS}
	@echo
	@echo Linking $@
	gcc -o $@ -Wall -g ${OBJS} -lm

${OBJS}: ${INCS} Makefile

test:
	./lab6

clean:
	rm -f *.o  lab6

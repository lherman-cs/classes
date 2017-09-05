# Makefile for Lab 10
CC = g++
CFLAGS = -g -Wall

OBJS= shape.o\
      circle.o\
      rectangle.o\
      triangle.o\
      main.o

INCS=shape.h rectangle.h circle.h triangle.h

lab10: ${OBJS}
	@echo
	@echo Linking $@
	g++ -o $@ -Wall -g ${OBJS} -lm

${OBJS}: ${INCS} Makefile

clean:
	rm -f *.o lab10 

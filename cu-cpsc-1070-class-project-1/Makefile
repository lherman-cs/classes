CC = g++
CFLAGS = -g -Wall
OBJS=main.o polynomial.o list.o node.o iterator.o

hw4: ${OBJS}
	@echo
	@echo Linking $@
	g++ -o $@ ${OBJS} -g


${OBJS}: polynomial.h list.h node.h iterator.h

clean:
	rm -f *.o hw4

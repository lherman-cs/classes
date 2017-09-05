C=gcc
CFLAGS=-g -Wall
OBJS = tester.o rgb.o

tester: ${OBJS}
	@echo Linking $@
	gcc -o $@ ${OBJS} -g

${OBJS}: rgb.h

clean:
	rm -f *.o tester

test:
	./testrgb


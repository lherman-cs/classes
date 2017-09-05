CC = g++
CFLAGS = -Wall -c
OBJS = recursiveFun.o main.o

hw5: ${OBJS}
	@echo
	@echo Linking $@
	${CC} -o $@ ${OBJS}

%.o: %.cpp
	@echo
	@echo Compiling $<
	${CC} ${CFLAGS} $< 2> $*.err
	@cat $*.err

clean:
	rm -f *.err *.o hw5

test:
	@./test.sh

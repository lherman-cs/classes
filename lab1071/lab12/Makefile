CC = g++
CFLAGS = -Wall -c
OBJS = maze.o

maze: ${OBJS}
	@echo
	@echo Linking $@
	${CC} -o $@ ${OBJS}

%.o: %.cpp
	@echo
	@echo Compiling $<
	${CC} ${CFLAGS} $< 2> $*.err
	@cat $*.err

clean:
	rm -f *.err *.o maze

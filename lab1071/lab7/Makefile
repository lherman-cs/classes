CC = g++
CFLAGS = -Wall -c
OBJS = lab7test.o odometer.o

lab7: ${OBJS}
	@echo
	@echo Linking $@
	${CC} -o $@ ${OBJS}

%.o: %.cpp
	@echo
	@echo Compiling $<
	${CC} ${CFLAGS} $< 2> $*.err
	@cat $*.err

clean:
	rm -f *.err *.o lab7

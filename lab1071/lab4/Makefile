# Makefile for lab 4
OBJS= main.o \
	pos.o \
	neg.o 

lab4: ${OBJS}
	@echo
	@echo Linking $@
	gcc -o $@ -Wall -g ${OBJS}

.c.o: $<
	@echo
	@echo Compiling $*.c
	gcc -c -Wall -c -g $< 2> ${@:.o=.err}
	@cat $*.err

${OBJS}: Makefile

clean: 
	rm -f *.o *.err lab4 task1

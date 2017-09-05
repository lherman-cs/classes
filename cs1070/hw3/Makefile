C=gcc
CFLAGS=-g -Wall
OBJS = hw3.o getImage.o readVals.o newImage.o outImage.o duotone.o

hw3: ${OBJS}
	@echo Linking $@
	gcc -o $@ ${OBJS} -g


${OBJS}: image.h readVals.h

clean:
	rm -f *.o hw3

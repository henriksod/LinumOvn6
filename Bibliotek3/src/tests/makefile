CC=gcc
LIBDIR = $(shell pwd)/../
CFLAGS = -g -pedantic -Wall -lm $(LIBDIR)libcomponent.so

OBJ = libcomponent_test.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

libcomponent_test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	
clean:
	-rm -f *.o *~ CORE *~
	-rm -f libcomponent_test *~ CORE *~

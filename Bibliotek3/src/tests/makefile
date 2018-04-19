CC=gcc
LIBDIR = $(shell pwd)/../
CFLAGS = -g -pedantic -Wall -lm -Wl,$(LIBDIR)libcomponent.so

OBJ = libcomponent_test.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

libcomponent_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
.PHONY: clean
clean:
	-rm -f $(TARGET) $(OBJ)

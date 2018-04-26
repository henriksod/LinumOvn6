CC=gcc
LIBDIR = $(shell pwd)/../../
CFLAGS = -Wall 
LDFLAGS = -Wl,$(LIBDIR)libpower.so
RM = -rm -f

TARGET  = test_libpower
SOURCES = test_libpower.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)
	
.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJECTS)


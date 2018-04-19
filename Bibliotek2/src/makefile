CC = gcc
CFLAGS = -fPIC -Wall -Werror
LDFLAGS = -shared -fPIC
RM = -rm -f

TARGET  = libpower.so
SOURCES = power.c
HEADERS = power.h
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $<

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJECTS)


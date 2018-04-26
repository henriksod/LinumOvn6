CC = gcc
CFLAGS = -fPIC -Wall -Werror
LDFLAGS = -shared -fPIC
RM = -rm -f
SRCDIR = src

TARGET  = libpower.so
SOURCES = $(SRCDIR)/power.c
HEADERS = $(SRCDIR)/power.h
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)
lib: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $<

clean:
	$(RM) $(TARGET) $(OBJECTS)

.PHONY: all lib clean


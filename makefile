CC = gcc
CFLAGS = -Wall 
LDFLAGSLOCAL = -lm -Wl,$(LIBOUTDIR)/libresistance.so -Wl,$(LIBOUTDIR)/libpower.so -Wl,$(LIBOUTDIR)/libcomponent.so
LDFLAGS = -lm -lresistance -lpower -lcomponent
RM = -rm -f

TARGET  = electrotest
SOURCES = electrotest.c
OBJECTS = $(SOURCES:.c=.o)

LIBS := Bibliotek1 Bibliotek2 Bibliotek3
LIBOUTDIR := ./lib
LIBSUBDIRS := . $(shell find $(LIBS) -type d)
OBJTYPES := *.o *.so
LIBOBJ := $(foreach DIR,$(LIBSUBDIRS),$(addprefix $(DIR)/,$(OBJTYPES)))

lib: $(LIBS)

all: $(OBJECTS) $(LIBS) copylibslocal
	$(CC) $(CFLAGS) -o $(TARGET) $< $(LDFLAGSLOCAL)

install: $(OBJECTS) $(LIBS) copylibs
	$(CC) $(CFLAGS) -o $(TARGET) $< $(LDFLAGS) 
	cp $(TARGET) /usr/bin

$(LIBS):
	$(MAKE) -C $@

clean:
	$(RM) $(TARGET) $(OBJECTS) $(LIBOBJ)
	$(RM) -r $(LIBOUTDIR)

uninstall : 
	$(RM) $(TARGET) $(OBJECTS) $(LIBOBJ)
	$(RM) /usr/bin/$(TARGET)
	$(RM) /usr/lib/libresistance.so
	$(RM) /usr/lib/libpower.so
	$(RM) /usr/lib/libcomponent.so

$(LIBOUTDIR)/:
	mkdir -p $@

copylibs:
	cp Bibliotek1/libresistance.so /usr/lib
	cp Bibliotek2/libpower.so /usr/lib
	cp Bibliotek3/src/libcomponent.so /usr/lib

copylibslocal:  | $(LIBOUTDIR)/
	cp Bibliotek1/libresistance.so $(LIBOUTDIR)
	cp Bibliotek2/libpower.so $(LIBOUTDIR)
	cp Bibliotek3/src/libcomponent.so $(LIBOUTDIR)

	
.PHONY: $(LIBDIRS) $(LIBOUTDIR) $(LIBS) all lib clean copylibs copylibslocal install uninstall



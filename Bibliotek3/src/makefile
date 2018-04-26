TOPTARGETS := all clean

SUBDIRS := $(wildcard */.)
LIB := lib

$(TOPTARGETS): $(LIB) $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

$(LIB):
	$(MAKE) -f makefile.lib $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS) $(LIB) 

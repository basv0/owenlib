CPP=g++
LD=gcc
CFLAGS=-c -fpic -Wall
LFLAGS=-shared
SOURCES=owen_hash.cpp port_io.cpp owen_io.cpp
OBJECTS=$(SOURCES:.cpp=.o)
SHAREDOBJ=libowen_io.so

all: $(SOURCES) $(SHAREDOBJ)

$(SHAREDOBJ): $(OBJECTS)
	$(LD) $(LFLAGS) $(OBJECTS) -o $@
	
.cpp.o:
	$(CPP) $(CFLAGS) $< -o $@
	
clean:
	rm $(OBJECTS) $(SHAREDOBJ)
	
install:
	cp $(SHAREDOBJ) /usr/local/lib/
	mkdir /usr/local/include/owen
	cp owen_io.h /usr/local/include/owen/
	echo /usr/local/lib > /etc/ld.so.conf.d/owen_io
	ldconfig
uninstall:
	rm /usr/local/lib/$(SHAREDOBJ)
	rm /usr/local/include/owen/owen_io.h
	rm /etc/ld.so.conf.d/owen_io
	ldconfig

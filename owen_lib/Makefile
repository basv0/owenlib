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
	cp $(SHAREDOBJ) /usr/lib64/
	cp owen_io.h /usr/include/
	
uninstall:
	rm /usr/lib64/$(SHAREDOBJ)
	rm /usr/include/owen_io.h


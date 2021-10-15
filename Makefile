CC=gcc
CFLAGS=-Wall
DEFS=-DMAX_SIZE=2048
ELEMS=5000

CFILES=main.c hashmap.c
OBJECTS=main.o hashmap.o

BINARY=main

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

data:
	./misc/genData.sh $(ELEMS) > debug.c
	$(CC) $(CFLAGS) $(DEFS) debug.c hashmap.c -o debug

clean:
	rm -rf $(BINARY) $(OBJECTS) debug*

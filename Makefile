CC=gcc
CFLAGS=-Wall -Wextra

CFILES=main.c hashmap.c
OBJECTS=main.o hashmap.o

BINARY=main

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)

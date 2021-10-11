#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

#ifndef MAP_SIZE
#define MAP_SIZE 5
#endif

int main(int argc, char **argv) {
    map_t *hashtable = createMap(MAP_SIZE);
    //printf("%zu\n", map("Alpha", sizeof(char *), MAP_SIZE));
    insert(hashtable, "Key1", "This is some data");
    insert(hashtable, "Key2", "This is some more data");
    insert(hashtable, "Key3", "Even more data");
    insert(hashtable, "Key3", "Even more data");
    insert(hashtable, "Key3", "LMAO");
    insert(hashtable, "Key3", "nice");
    insert(hashtable, "Key4", "Even nicer");
    insert(hashtable, "Key5", "the best");
    insert(hashtable, "Key5", "brah");
    insert(hashtable, "Key6", "brain");
    insert(hashtable, "Key7", "mochi");
    insert(hashtable, "Key7", "ekul");
    insert(hashtable, "Key7", "Even more data");
    printMap(hashtable);
    printf("Load factor: %0.2f\n", hashtable->loadFactor);
    return 0;
}

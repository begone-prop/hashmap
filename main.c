#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

#ifndef MAP_SIZE
#define MAP_SIZE 10
#endif

int main(int argc, char **argv) {
    map_t *hashtable = createMap(MAP_SIZE);
    //printf("%zu\n", map("Alpha", sizeof(char *), MAP_SIZE));
    list_t *node = createNode("Alpha", "This is some data");
    insert(hashtable, node);
    insert(hashtable, createNode("Beta", "This is some more data"));
    insert(hashtable, createNode("Gamma", "Even more data"));
    insert(hashtable, createNode("Delta", "Even more data"));
    insert(hashtable, createNode("Sigma", "LMAO"));
    insert(hashtable, createNode("ligma", "nice"));
    insert(hashtable, createNode("ligma", "Even nicer"));
    insert(hashtable, createNode("ligma", "the best"));
    insert(hashtable, createNode("NIgga", "brah"));
    /*insert(hashtable, createNode("figma", "brain"));*/
    /*insert(hashtable, createNode("sochi", "mochi"));*/
    /*insert(hashtable, createNode("luke", "ekul"));*/
    //insert(hashtable, createNode("Delta", "Even more data"));
    printMap(hashtable);
    printf("Load factor: %0.2f\n", hashtable->loadFactor);
    return 0;
}

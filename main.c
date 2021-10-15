#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

#ifndef MAP_SIZE
#define MAP_SIZE  5
#endif

int main(int argc, char **argv) {
    map_t hashtable = createMap(MAP_SIZE);
    insert(&hashtable, "Key1", "based");
    insert(&hashtable, "Key1", "This is some data");
    insert(&hashtable, "Key2", "This is some more data");
    insert(&hashtable, "Key3", "more data");
    insert(&hashtable, "Key3", "Even more data");
    insert(&hashtable, "Key4", "Even nicer");
    insert(&hashtable, "Key2", "This is some more data");
    insert(&hashtable, "Key3", "More data");
    insert(&hashtable, "Key3", "Even more data");
    insert(&hashtable, "Key3", "LMAO");
    insert(&hashtable, "Key3", "nice");
    insert(&hashtable, "Key4", "Even nicer");
    insert(&hashtable, "Key6", "brain");
    insert(&hashtable, "Key5", "brah");
    insert(&hashtable, "Key7", "mochi");
    insert(&hashtable, "Key7", "ekul");
    insert(&hashtable, "Key7", "ligma");
    insert(&hashtable, "Key8", "eight");
    insert(&hashtable, "Key9", "nine");

    list_t *data = find(hashtable, "Key3");
    if(!data) printf("%p\n", data);
    else printf("%s\t%s\n", data->key, data->data);

    list_t *node = find(hashtable, "nokey");
    if(!node) printf("%p\n", node);
    else printf("%s\t%s\n", node->key, node->data);

    printMap(hashtable);
    drop(&hashtable, "Key1");
    drop(&hashtable, "Key2");
    drop(&hashtable, "Key3");
    drop(&hashtable, "Key4");
    drop(&hashtable, "Key5");
    drop(&hashtable, "Key6");
    drop(&hashtable, "Key7");
    drop(&hashtable, "Key8");
    drop(&hashtable, "Key9");
    printMap(hashtable);
    deleteMap(&hashtable);
    //printMap(hashtable);
    return 0;
}

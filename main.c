#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

#ifndef MAP_SIZE
#define MAP_SIZE 5
#endif

int main(int argc, char **argv) {
    map_t hashtable = createMap(MAP_SIZE);
    insert(&hashtable, "Key1", "based");
    insert(&hashtable, "Key1", "This is some data");
    insert(&hashtable, "Key2", "This is some more data");
    insert(&hashtable, "Key3", "more data");
    insert(&hashtable, "Key3", "Even more data");
    insert(&hashtable, "Key4", "Even nicer");
    /*insert(&hashtable, "Key2", "This is some more data");*/
    /*insert(&hashtable, "Key3", "More data");*/
    /*insert(&hashtable, "Key3", "Even more data");*/
    /*insert(&hashtable, "Key3", "LMAO");*/
    /*insert(&hashtable, "Key3", "nice");*/
    /*insert(&hashtable, "Key4", "Even nicer");*/

    /*insert(&hashtable, "Key6", "brain");*/
    /*insert(&hashtable, "Key5", "brah");*/
    /*insert(&hashtable, "Key7", "mochi");*/
    /*insert(&hashtable, "Key7", "ekul");*/
    /*insert(&hashtable, "Key7", "ligma");*/
    /*insert(&hashtable, "Key8", "eight");*/
    /*insert(&hashtable, "Key9", "nine");*/
    //printMap(hashtable);
    printMap(hashtable);
    deleteMap(&hashtable);
    printMap(hashtable);

    /*printMap(hashtable);*/
    //find(hashtable, "Key7");
    //printf("%s\n", data);
    //deleteMap(&hashtable);
    return 0;
}

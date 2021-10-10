#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

map_t *createMap(size_t mapSize) {
    map_t *newMap = (map_t *) malloc(sizeof(map_t));
    newMap->slots = (list_t **) malloc(mapSize * sizeof(list_t *));

    for(size_t i = 0; i <= mapSize; i++) {
        newMap->slots[i] = NULL;
    }

    newMap->taken = 0;
    newMap->loadFactor = 0;
    newMap->size = mapSize;
    return newMap;
}

list_t *createNode(char *key, char *data) {
    list_t *node = (list_t *) malloc(sizeof(list_t));
    node->key = strdup(key);
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

size_t map(void *key, size_t len, size_t mapSize) {
    unsigned char *p = key;
    size_t idx = 0x811c9dc5;
    for(size_t i = 0; i < len; i++)
        idx = (idx ^ p[i]) * 0x01000193;

    idx %= mapSize;
    return idx;
}

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <stddef.h>

typedef struct list_t {
    char *key;
    char *data;
    struct list_t *next;
} list_t;

typedef struct map_t {
    list_t **slots;
    size_t size;
    size_t taken;
    float loadFactor;
} map_t;

size_t map(void *, size_t, size_t);
list_t *createNode(char *, char *);
map_t *createMap(size_t);
void printList(list_t **);
void printMap(map_t *);
void insert(map_t *, list_t *);

#endif

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <stddef.h>

#ifndef LOAD_THRESHOLD
#define LOAD_THRESHOLD 0.7
#endif

typedef struct list_t {
    char *key;
    char *data;
    struct list_t *next;
} list_t;

typedef struct map_t {
    list_t **slots;
    size_t size;
    size_t taken;
} map_t;

map_t createMap(size_t);
list_t *find(map_t, char *);
size_t map(char *, size_t, size_t);
void deleteMap(map_t *);
void grow(map_t *);
void insert(map_t *, char *, char *);
void printList(list_t *);
void printMap(map_t);
#endif

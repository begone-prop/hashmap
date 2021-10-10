#ifndef HASHMAP
#define HASHMAP
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

#endif

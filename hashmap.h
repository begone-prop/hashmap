#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <stddef.h>

#ifndef GROW_THRESHOLD
#define GROW_THRESHOLD 0.7
#endif

#ifndef SHRINK_THRESHOLD
#define SHRINK_THRESHOLD 0.25
#endif

#ifndef MIN_SIZE
#define MIN_SIZE 8
#endif

#ifndef MAX_SIZE
#define MAX_SIZE 256
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
void drop(map_t *, char *);
void resize(map_t *, float);
void insert(map_t *, char *, char *);
void printList(list_t *);
void printMap(map_t);
#endif

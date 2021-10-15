#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashmap.h"

static void freeList(list_t *);
static list_t *createNode(char *, char *);
static list_t *search(list_t *, char *);

void resize(map_t *hashmap, float ammount) {
    if(ammount < 0) return;
    size_t newSize = hashmap->size * ammount;
    map_t newMap = createMap(newSize);

    for(size_t i = 0; i < hashmap->size; i++) {
        list_t *current = hashmap->slots[i];
        while(current) {
            size_t idx = map(current->key, strlen(current->key), newMap.size);
            list_t *next = current->next;
            current->next = newMap.slots[idx];
            newMap.slots[idx] = current;
            current = next;
        }
    }

    free(hashmap->slots);
    hashmap->slots = newMap.slots;
    hashmap->size = newSize;
}

void insert(map_t *entry, char *key, char *data) {
    if((float) (entry->taken + 1) / entry->size >= GROW_THRESHOLD &&
            entry->size * 2 <= MAX_SIZE) {
        resize(entry, 2);
    }

    size_t idx = map(key, strlen(key), entry->size);
    list_t *update = search(entry->slots[idx], key);
    if(update) {
        free(update->data);
        update->data = strdup(data);
        return;
    }

    list_t *node = createNode(key, data);
    node->next = entry->slots[idx];
    entry->slots[idx] = node;
    entry->taken++;
}

void drop(map_t *hashmap, char *key) {
    if((float) hashmap->taken / hashmap->size < SHRINK_THRESHOLD &&
            hashmap->size >= MIN_SIZE) {
        resize(hashmap, 0.5);
    }

    size_t idx = map(key, strlen(key), hashmap->size);
    list_t *head = hashmap->slots[idx];

    if(head && !strcmp(head->key, key)) {
        list_t *next = head->next;
        free(head->key);
        free(head->data);
        free(head);
        hashmap->slots[idx] = next;
        next = hashmap->slots[idx];
        hashmap->taken--;
    } else {
        for(list_t *current = head; current; current = current->next) {
            list_t *next = current->next;
            if(next && !strcmp(next->key, key)) {
                free(next->key);
                free(next->data);
                current->next = next->next;
                free(next);
                hashmap->taken--;
                break;
            }
        }
    }
}

list_t *search(list_t *head, char *key) {
    if(!head) return NULL;
    if(!strcmp(head->key, key)) return head;
    return search(head->next, key);
}

list_t *find(map_t hashmap, char *key) {
    size_t idx = map(key, strlen(key), hashmap.size);
    return search(hashmap.slots[idx], key);
}

map_t createMap(size_t mapSize) {
    map_t newMap;
    list_t **heads = malloc(mapSize * sizeof(list_t *));
    newMap.slots = heads;

    for(size_t i = 0; i < mapSize; i++)
        newMap.slots[i] = NULL;

    newMap.taken = 0;
    newMap.size = mapSize;
    return newMap;
}

void deleteMap(map_t *hashmap) {
    hashmap->size = 0;
    hashmap->taken = 0;

    for(size_t i = 0; i < hashmap->size; i++) freeList(hashmap->slots[i]);
    free(hashmap->slots);
}

size_t map(char *key, size_t len, size_t mapSize) {
    size_t idx = 0x811c9dc5;

    for(size_t i = 0; i < len; i++)
        idx = (idx ^ key[i]) * 0x01000193;

    idx %= mapSize;
    return idx;
}

void printMap(map_t hashmap) {
    for(size_t j = 0; j < hashmap.size; j++) {
        printf("[%02zu]:\t", j);
        if(hashmap.slots[j]) printList(hashmap.slots[j]);
        else printf("null\n");
    }
    printf("Size: %zu Items: %zu Load: %0.2f\n", hashmap.size,
            hashmap.taken,
            !hashmap.size ? 0 : (float) hashmap.taken / hashmap.size );
}

void printList(list_t *head) {
    if(!head) return;
    printf("(%s, %s) %s", head->key, head->data, head->next ? "-> " : "\n");
    printList(head->next);
}

list_t *createNode(char *key, char *data) {
    list_t *node = malloc(sizeof(list_t *));
    node->key = strdup(key);
    node->data = strdup(data); node->next = NULL;
    return node;
}

void freeList(list_t *head) {
    if(!head) return;
    freeList(head->next);
    free(head->key);
    free(head->data);
}

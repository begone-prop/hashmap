#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashmap.h"

void grow(map_t **entry) {
    map_t *oldMap = *entry;
    size_t newSize = oldMap->size * 2;
    map_t *newMap = createMap(newSize);

    for(size_t i = 0; i < oldMap->size; i++) {
        list_t *current = oldMap->slots[i];
        while(current) {
            size_t idx = map(current->key, strlen(current->key), newMap->size);
            list_t *next = current->next;
            current->next = newMap->slots[idx];
            newMap->slots[idx] = current;
            current = next;
        }
        oldMap->slots[i] = NULL;
    }

    newMap->size = newSize;
    newMap->taken = oldMap->taken;
    newMap->load = (float) newMap->taken / newSize;
    *entry = newMap;
    free(oldMap->slots);
    free(oldMap);
}

void insert(map_t **entry, char *key, char *data) {
    if((*entry)->load >= LOAD_THRESHOLD)
        grow(entry);

    map_t *hashmap = *entry;
    size_t idx = map(key, sizeof(char *), hashmap->size);
    list_t *current = hashmap->slots[idx];

    for(; current; current = current->next) {
        if(!strcmp(current->key, key)) {
            free(current->data);
            current->data = strdup(data);
            return;
        }
    }

    list_t *node = createNode(key, data);
    node->next = hashmap->slots[idx];
    hashmap->slots[idx] = node;
    hashmap->taken++;
    hashmap->load = (float) hashmap->taken / hashmap->size;
}

map_t *createMap(size_t mapSize) {
    map_t *newMap = (map_t *) malloc(sizeof(map_t));
    newMap->slots = (list_t **) malloc(mapSize * sizeof(list_t *));

    for(size_t i = 0; i < mapSize; i++) {
        newMap->slots[i] = NULL;
    }

    newMap->taken = 0;
    newMap->load = 0;
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

size_t map(char *key, size_t len, size_t mapSize) {
    size_t idx = 0x811c9dc5;

    for(size_t i = 0; i < len; i++)
        idx = (idx ^ key[i]) * 0x01000193;

    idx %= mapSize;
    return idx;
}

void printList(list_t **head) {
    list_t *current = *head;
    if(!current) return;
    printf("(%s, %s) %s", current->key, current->data, current->next ? "-> " : "\n");
    printList(&current->next);
}

void printMap(map_t *hashmap) {
    for(size_t j = 0; j < hashmap->size; j++) {
        printf("[%02zu]:\t", j);
        if(hashmap->slots[j]) printList(&hashmap->slots[j]);
        else printf("null\n");
    }
    printf("Size: %zu Items: %zu Load: %0.2f\n", hashmap->size, hashmap->taken, hashmap->load);
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashmap.h"

void insert(map_t *hashMap, char *key, char *data) {
    size_t idx = map(key, sizeof(char *), hashMap->size);

    list_t *current = hashMap->slots[idx];

    for(; current; current = current->next) {
        if(!strcmp(current->key, key)) {
            current->data = strdup(data);
            break;
        }
    }

    if(!current) {
        list_t *node = createNode(key, data);
        node->next = hashMap->slots[idx];
        hashMap->slots[idx] = node;
    }

    hashMap->taken++;
    hashMap->loadFactor = (float) hashMap->taken / hashMap->size;
}

map_t *createMap(size_t mapSize) {
    map_t *newMap = (map_t *) malloc(sizeof(map_t));
    newMap->slots = (list_t **) malloc(mapSize * sizeof(list_t *));

    for(size_t i = 0; i < mapSize; i++) {
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
    return printList(&current->next);
}

void printMap(map_t *hashMap) {
    for(size_t j = 0; j < hashMap->size; j++) {
        printf("[%02zu]:\t", j);
        if(hashMap->slots[j]) printList(&hashMap->slots[j]);
        else printf("null\n");
    }
}

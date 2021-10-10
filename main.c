#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

int main(int argc, char **argv) {
    map_t *map = createMap(10);
    printMap(map);
    return 0;
}

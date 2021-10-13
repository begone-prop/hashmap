#!/bin/sh

numLines=${1:-100}
numChars=${2:-50}

printf '#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
int main(void) { map_t *hashtable = createMap(10);\n'

grep -m 5000 -Ezaoi '[a-z]' /dev/urandom | tr -d '\0' |
    fold -w "$numChars" | shuf | nl |
    sed -E 's/\s+/ /g;
    s/\s([[:digit:]]*)\s(.*)/insert\(\&hashtable, "KEY\1", "\2"\);/g' |
    head -n "$numLines"

printf 'printMap(hashtable); return(0); }\n'

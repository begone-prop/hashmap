#!/bin/sh

numLines=${1:-100}
numChars=${2:-50}
MAXLINES=100000

printf '#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
int main(void) { map_t *hashtable = createMap(10);\n'

grep -m "$MAXLINES" -Ezaoi '[a-z]' /dev/urandom | tr -d '\0' |
    fold -w "$numChars" | nl -w 1 -s ' ' |
    sed -E 's/([[:digit:]]*)\s(.*)/insert\(\&hashtable, "KEY\1", "\2"\);/g' |
    head -n "$numLines"

printf 'printMap(hashtable); return(0);}\n'

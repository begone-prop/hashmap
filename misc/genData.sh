#!/bin/sh

numLines=${1:-100}
numChars=${2:-50}
MAXLINES=100000

printf '#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
int main(void) { map_t ht = createMap(5);\n'

grep -aoim "$MAXLINES" '[a-z]' /dev/urandom | tr -d '\n' |
    fold -w "$numChars" | nl -w 1 -s ' ' |
    sed -E 's/([[:digit:]]*)\s(.*)/insert\(\&ht, "KEY\1", "\2"\);/g' |
    head -n "$numLines"

printf 'printMap(ht); deleteMap(&ht); printMap(ht); return(0);}\n'

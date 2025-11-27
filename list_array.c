#include <stdio.h>
#include <string.h>
#include "list_array.h"

void array_init(ArrayList *a) {
    a->size = 0;
}

int array_insert(ArrayList *a, Item it) {
    if(a->size >= MAX_ITEMS) return 0;
    a->items[a->size++] = it;
    return 1;
}

int array_insert_at(ArrayList *a, Item it, int pos) {
    if(a->size >= MAX_ITEMS) return 0;
    if(pos < 0 || pos > a->size) return 0;
    for(int i = a->size; i > pos; --i) a->items[i] = a->items[i-1];
    a->items[pos] = it;
    a->size++;
    return 1;
}

int array_remove_at(ArrayList *a, int pos) {
    if(pos < 0 || pos >= a->size) return 0;
    for(int i = pos; i < a->size-1; ++i) a->items[i] = a->items[i+1];
    a->size--;
    return 1;
}

int array_find_seq(ArrayList *a, const char *name) {
    for(int i=0;i<a->size;i++) {
        if(strcmp(a->items[i].name, name) == 0) return i;
    }
    return -1;
}

void array_print(ArrayList *a) {
    printf(\"ArrayList (size=%d):\\n\", a->size);
    for(int i=0;i<a->size;i++) {
        printf(\" %2d: %-20s | priority=%d\\n\", i, a->items[i].name, a->items[i].priority);
    }
}

#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int priority; // menor = mais importante
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int size;
} ArrayList;

/* operations */
void array_init(ArrayList *a);
int array_insert(ArrayList *a, Item it); /* append if space */
int array_insert_at(ArrayList *a, Item it, int pos); /* insert at index pos */
int array_remove_at(ArrayList *a, int pos);
int array_find_seq(ArrayList *a, const char *name); /* sequential search, returns index or -1 */
void array_print(ArrayList *a);
#endif

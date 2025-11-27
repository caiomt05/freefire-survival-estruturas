#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include "list_array.h"

typedef struct Node {
    Item data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

/* operations */
void list_init(LinkedList *l);
void list_insert_front(LinkedList *l, Item it);
void list_insert_back(LinkedList *l, Item it);
int list_remove_name(LinkedList *l, const char *name); /* returns 1 if removed */
Node* list_find(LinkedList *l, const char *name);
void list_print(LinkedList *l);
void list_free(LinkedList *l);
#endif

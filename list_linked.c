#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_linked.h"

void list_init(LinkedList *l) {
    l->head = NULL;
    l->size = 0;
}

void list_insert_front(LinkedList *l, Item it) {
    Node *n = (Node*) malloc(sizeof(Node));
    strcpy(n->data.name, it.name);
    n->data.priority = it.priority;
    n->next = l->head;
    l->head = n;
    l->size++;
}

void list_insert_back(LinkedList *l, Item it) {
    Node *n = (Node*) malloc(sizeof(Node));
    strcpy(n->data.name, it.name);
    n->data.priority = it.priority;
    n->next = NULL;
    if(!l->head) l->head = n;
    else {
        Node *cur = l->head;
        while(cur->next) cur = cur->next;
        cur->next = n;
    }
    l->size++;
}

int list_remove_name(LinkedList *l, const char *name) {
    Node *prev = NULL, *cur = l->head;
    while(cur) {
        if(strcmp(cur->data.name, name) == 0) {
            if(prev) prev->next = cur->next;
            else l->head = cur->next;
            free(cur);
            l->size--;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

Node* list_find(LinkedList *l, const char *name) {
    Node *cur = l->head;
    while(cur) {
        if(strcmp(cur->data.name, name) == 0) return cur;
        cur = cur->next;
    }
    return NULL;
}

void list_print(LinkedList *l) {
    printf(\"LinkedList (size=%d):\\n\", l->size);
    Node *cur = l->head;
    int i = 0;
    while(cur) {
        printf(\" %2d: %-20s | priority=%d\\n\", i++, cur->data.name, cur->data.priority);
        cur = cur->next;
    }
}

void list_free(LinkedList *l) {
    Node *cur = l->head;
    while(cur) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    l->head = NULL;
    l->size = 0;
}

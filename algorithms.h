#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "list_array.h"

/* Sorting */
typedef struct {
    long comparisons;
    long movements;
} Stats;

void selection_sort(Item arr[], int n, Stats *st); /* sorts by name */
void selection_sort_by_priority(Item arr[], int n, Stats *st);

/* Binary search */
int binary_search_iterative(Item arr[], int n, const char *key, Stats *st);
int binary_search_recursive(Item arr[], int l, int r, const char *key, Stats *st);

#endif

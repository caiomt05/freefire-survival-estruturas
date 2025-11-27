#include <string.h>
#include "algorithms.h"

/* selection sort by name (lexicographic) */
void selection_sort(Item arr[], int n, Stats *st) {
    st->comparisons = 0;
    st->movements = 0;
    for(int i=0;i<n-1;i++) {
        int minidx = i;
        for(int j=i+1;j<n;j++) {
            st->comparisons++;
            if(strcmp(arr[j].name, arr[minidx].name) < 0) minidx = j;
        }
        if(minidx != i) {
            Item tmp = arr[i];
            arr[i] = arr[minidx];
            arr[minidx] = tmp;
            st->movements += 3; /* approximate count (assignments) */
        }
    }
}

/* selection sort by priority (ascending) */
void selection_sort_by_priority(Item arr[], int n, Stats *st) {
    st->comparisons = 0;
    st->movements = 0;
    for(int i=0;i<n-1;i++) {
        int minidx = i;
        for(int j=i+1;j<n;j++) {
            st->comparisons++;
            if(arr[j].priority < arr[minidx].priority) minidx = j;
        }
        if(minidx != i) {
            Item tmp = arr[i];
            arr[i] = arr[minidx];
            arr[minidx] = tmp;
            st->movements += 3;
        }
    }
}

/* binary search iterative (searching by name in sorted array) */
int binary_search_iterative(Item arr[], int n, const char *key, Stats *st) {
    int l = 0, r = n-1;
    st->comparisons = 0;
    while(l <= r) {
        int m = l + (r - l)/2;
        st->comparisons++;
        int cmp = strcmp(arr[m].name, key);
        if(cmp == 0) return m;
        else if(cmp < 0) l = m+1;
        else r = m-1;
    }
    return -1;
}

/* recursive binary search */
int binary_search_recursive(Item arr[], int l, int r, const char *key, Stats *st) {
    if(l > r) return -1;
    int m = l + (r - l)/2;
    st->comparisons++;
    int cmp = strcmp(arr[m].name, key);
    if(cmp == 0) return m;
    else if(cmp < 0) return binary_search_recursive(arr, m+1, r, key, st);
    else return binary_search_recursive(arr, l, m-1, key, st);
}

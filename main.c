#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_array.h"
#include "list_linked.h"
#include "algorithms.h"

void sample_items(ArrayList *a) {
    array_init(a);
    Item it;
    strcpy(it.name, "Bandage"); it.priority = 5; array_insert(a, it);
    strcpy(it.name, "MedKit"); it.priority = 1; array_insert(a, it);
    strcpy(it.name, "AR"); it.priority = 2; array_insert(a, it);
    strcpy(it.name, "SMG"); it.priority = 3; array_insert(a, it);
    strcpy(it.name, "Shield"); it.priority = 4; array_insert(a, it);
}

/* helper to copy ArrayList into Item[] */
void to_array(ArrayList *a, Item out[], int *n) {
    for(int i=0;i<a->size;i++) out[i] = a->items[i];
    *n = a->size;
}

void demo_array_vs_list() {
    ArrayList a;
    sample_items(&a);
    printf(\"-- Demo vetor (inserir e remover) --\\n\");
    array_print(&a);
    Item it; strcpy(it.name, \"Grenade\"); it.priority = 2;
    printf(\"Inserindo Grenade no índice 2...\\n\");
    array_insert_at(&a, it, 2);
    array_print(&a);
    printf(\"Removendo elemento na pos 3...\\n\");
    array_remove_at(&a, 3);
    array_print(&a);

    LinkedList l; list_init(&l);
    printf(\"\\n-- Demo lista encadeada (inserir/remover) --\\n\");
    for(int i=0;i<a.size;i++) list_insert_back(&l, a.items[i]);
    list_print(&l);
    printf(\"Inserindo Grenade na frente...\\n\");
    list_insert_front(&l, it);
    list_print(&l);
    printf(\"Removendo 'AR' da lista...\\n\");
    list_remove_name(&l, \"AR\");
    list_print(&l);
    list_free(&l);
}

void demo_search_and_sort() {
    ArrayList a;
    sample_items(&a);
    Item arr[100]; int n;
    to_array(&a, arr, &n);

    Stats st;
    printf(\"\\n-- Selection Sort (por nome) --\\n\");
    selection_sort(arr, n, &st);
    for(int i=0;i<n;i++) printf(\" %s\\n\", arr[i].name);
    printf(\"Comparisons=%ld movements=%ld\\n\", st.comparisons, st.movements);

    printf(\"\\n-- Binary Search Iterative (buscar 'Shield') --\\n\");
    st.comparisons = 0;
    int idx = binary_search_iterative(arr, n, \"Shield\", &st);
    printf(\"Found at index %d (comparisons=%ld)\\n\", idx, st.comparisons);

    printf(\"\\n-- Binary Search Recursive (buscar 'MedKit') --\\n\");
    st.comparisons = 0;
    idx = binary_search_recursive(arr, 0, n-1, \"MedKit\", &st);
    printf(\"Found at index %d (comparisons=%ld)\\n\", idx, st.comparisons);
}

int main() {
    int opt;
    while(1) {
        printf(\"\\n=== FreeFire Survival - Menu ===\\n\");
        printf(\"1) Demo vetor vs lista\\n\");
        printf(\"2) Demo ordenacao e busca\\n\");
        printf(\"0) Sair\\n\");
        printf(\"Escolha: \");
        if(scanf(\"%d\", &opt)!=1) break;
        if(opt==0) break;
        if(opt==1) demo_array_vs_list();
        if(opt==2) demo_search_and_sort();
    }
    return 0;
}

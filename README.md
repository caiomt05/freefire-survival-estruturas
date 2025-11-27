# FreeFire Survival — Estruturas e Algoritmos em C
Trabalho de disciplina Caio Mateus — Implementação de listas, vetores, busca e ordenação em C.

## Objetivos
- Implementar listas estáticas (vetor) e dinâmicas (lista encadeada).
- Implementar inserção, remoção, percorrimento e busca sequencial.
- Comparar vetores e listas encadeadas em operações de inserção/removal.
- Implementar busca binária (iterativa e recursiva).
- Implementar Selection Sort e contar comparações e movimentos.
- Medir comparações em melhores, piores e casos médios.

## Compilar
```
make
```

ou

```
gcc -std=c99 -O2 -Iinclude -o survival src/main.c src/list_array.c src/list_linked.c src/algorithms.c
```

## Executar
```
./survival
```

O programa apresenta um menu interativo para testar:
- operações em vetor (inserir, remover, percorrer, busca sequencial)
- operações em lista encadeada (inserir, remover, percorrer, busca)
- busca binária (iterativa e recursiva) em array ordenado
- Selection Sort e contagem de comparações/movimentos em vários cenários
- comparação simples entre vetor e lista para inserções/removals

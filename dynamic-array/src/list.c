#include <stdlib.h>

#include "list.h"

List* List_new(unsigned int cap) {
    List* l = (List*) malloc(sizeof(List));
    l->cap = cap;
    l->elements = (int*) malloc(sizeof(int) * cap);

    return l;
}

void List_destroy(List* l) {
    free(l->elements);
    free(l);
}

void List_push(List* l, int val) {
    if (l->length >= l->cap) {
        List_extend(l);
    }

    l->elements[l->length++] = val;
}

int List_get(List* l, unsigned int idx) {
    if (idx >= l->cap) {
        return -1;
    }

    return l->elements[idx];
}

int List_pop(List* l) {
    if (l->length == 0) {
        return -1;
    }

    return l->elements[--l->length];
}

void List_extend(List* l) {
    l->cap = l->cap * 2;
    int* extendedElements = (int*) malloc(sizeof(int) * l->cap);

    for (unsigned int i = 0; i < l->length; i++) {
        extendedElements[i] = l->elements[i];
    }

    free(l->elements);
    l->elements = extendedElements;
}

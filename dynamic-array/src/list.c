#include <stdlib.h>

#include "list.h"

List* newDyn(unsigned int cap) {
    List* dyn = (List*) malloc(sizeof(List));
    dyn->cap = cap;
    dyn->elements = (int*) malloc(sizeof(int) * cap);

    return dyn;
}

void destroyDyn(List* dyn) {
    free(dyn->elements);
    free(dyn);
}

void pushDyn(List* dyn, int val) {
    if (dyn->length >= dyn->cap) {
        extendDyn(dyn);
    }

    dyn->elements[dyn->length++] = val;
}

int getDyn(List* dyn, unsigned int idx) {
    if (idx >= dyn->cap) {
        return -1;
    }

    return dyn->elements[idx];
}

int popDyn(List* dyn) {
    if (dyn->length == 0) {
        return -1;
    }

    return dyn->elements[--dyn->length];
}

void extendDyn(List* dyn) {
    dyn->cap = dyn->cap * 2;
    int* extendedElements = (int*) malloc(sizeof(int) * dyn->cap);

    for (unsigned int i = 0; i < dyn->length; i++) {
        extendedElements[i] = dyn->elements[i];
    }

    free(dyn->elements);
    dyn->elements = extendedElements;
}

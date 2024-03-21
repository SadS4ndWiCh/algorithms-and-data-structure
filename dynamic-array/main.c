#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int cap;
    unsigned int length;
    int* elements;
} DynamicArray;

DynamicArray* newDyn(unsigned int cap);
void destroyDyn(DynamicArray* dyn);
void pushDyn(DynamicArray* dyn, int val);
int getDyn(DynamicArray* dyn, unsigned int idx);
int popDyn(DynamicArray* dyn);
void insertDyn(DynamicArray* dyn);
void extendDyn(DynamicArray* dyn);

DynamicArray* newDyn(unsigned int cap) {
    DynamicArray* dyn = (DynamicArray*) malloc(sizeof(DynamicArray));
    dyn->cap = cap;
    dyn->elements = (int*) malloc(sizeof(int) * cap);

    return dyn;
}

void destroyDyn(DynamicArray* dyn) {
    free(dyn->elements);
    free(dyn);
}

void pushDyn(DynamicArray* dyn, int val) {
    if (dyn->length >= dyn->cap) {
        extendDyn(dyn);
    }

    dyn->elements[dyn->length++] = val;
}

int getDyn(DynamicArray* dyn, unsigned int idx) {
    if (idx >= dyn->cap) {
        return -1;
    }

    return dyn->elements[idx];
}

int popDyn(DynamicArray* dyn) {
    if (dyn->length == 0) {
        return -1;
    }

    return dyn->elements[--dyn->length];
}

void extendDyn(DynamicArray* dyn) {
    dyn->cap = dyn->cap * 2;
    int* extendedElements = (int*) malloc(sizeof(int) * dyn->cap);

    for (unsigned int i = 0; i < dyn->length; i++) {
        extendedElements[i] = dyn->elements[i];
    }

    free(dyn->elements);
    dyn->elements = extendedElements;
}

int main() {
    DynamicArray* dyn = newDyn(2);

    pushDyn(dyn, 2);
    pushDyn(dyn, 5);
    pushDyn(dyn, 10);

    printf("%d\n", popDyn(dyn));
    printf("%d\n", popDyn(dyn));
    printf("%d\n", popDyn(dyn));

    destroyDyn(dyn);

    return 0;
}

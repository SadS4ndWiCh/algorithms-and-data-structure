#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int* arr;
} DynamicArray;

DynamicArray* newDynamicArray(int capacity);
int sizeDynamicArray(DynamicArray* arr);
int getDynamicArray(DynamicArray* arr, int idx);
int setDynamicArray(DynamicArray* arr, int idx, int val);
void resizeDynamicArray(DynamicArray* arr);

DynamicArray* newDynamicArray(int capacity) {
    DynamicArray* d = (DynamicArray*) malloc(sizeof(DynamicArray));
    d->capacity = capacity;
    d->arr = (int*) malloc(sizeof(int) * capacity);

    return d;
}

int getDynamicArray(DynamicArray* arr, int idx) {
    if (idx < 0 || arr->capacity <= idx) {
        return 0;
    }

    return arr->arr[idx];
}

int setDynamicArray(DynamicArray* arr, int idx, int val) {
    if (idx >= 0 && arr->capacity <= idx) {
        resizeDynamicArray(arr);
    }

    arr->arr[idx] = val;
    return 1;
}

int sizeDynamicArray(DynamicArray* arr) {
    int size = 0;

    while(arr->arr[size] != 0) {
        size++;
    }

    return size;
}

void resizeDynamicArray(DynamicArray* arr) {
    arr->capacity = arr->capacity * 2;
    int* extended = (int*) malloc(sizeof(int) * arr->capacity);

    for (int i = 0; i < arr->capacity; i++) {
        extended[i] = arr->arr[i];
    }

    free(arr->arr);
    arr->arr = extended;
}

int main() {
    DynamicArray* d = newDynamicArray(2);
    
    setDynamicArray(d, 0, 23);
    setDynamicArray(d, 1, 51);
    setDynamicArray(d, 2, 322);

    printf("%d\n", d->capacity);
    printf("%d\n", sizeDynamicArray(d));
    printf("%d\n", getDynamicArray(d, 0));

    free(d);

    return 0;
}

#include <stdlib.h>

#include "stack.h"

Stack* Stack_new(unsigned int cap) {
    Stack* stk = (Stack*) malloc(sizeof(Stack));
    stk->cap = cap;
    stk->elements = (int*) malloc(sizeof(int) * cap);

    return stk;
}

void Stack_push(Stack* stk, int val) {
    if (stk->length == stk->cap) {
        return;
    }

    stk->elements[stk->length++] = val;
}

int Stack_pop(Stack* stk) {
    if (stk->length == 0) {
        return -1;
    }

    return stk->elements[--stk->length];
}

void Stack_destroy(Stack* stk) {
    free(stk->elements);
    free(stk);
}

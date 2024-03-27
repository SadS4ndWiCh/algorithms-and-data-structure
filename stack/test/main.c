#include <stdio.h>

#include "../src/stack.h"

int main() {
    Stack* stk = Stack_new(5);

    Stack_push(stk, 5);
    printf("%d\n", stk->length);

    Stack_push(stk, 6);
    printf("%d\n", stk->length);

    Stack_push(stk, 10);
    printf("%d\n", stk->length);

    Stack_push(stk, 1);
    printf("%d\n", stk->length);

    Stack_push(stk, 19);
    printf("%d\n", stk->length);

    printf("%d\n", Stack_pop(stk));
    printf("%d\n", Stack_pop(stk));
    printf("%d\n", Stack_pop(stk));
    printf("%d\n", Stack_pop(stk));
    printf("%d\n", Stack_pop(stk));

    printf("%d\n", stk->length);

    return 0;
}

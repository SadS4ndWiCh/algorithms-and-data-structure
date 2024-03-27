#include <stdio.h>

#include "../src/list.h"

int main() {
    List* l = List_new(2);

    List_push(l, 2);
    List_push(l, 5);
    List_push(l, 10);

    printf("%d\n", List_pop(l));
    printf("%d\n", List_pop(l));
    printf("%d\n", List_pop(l));

    List_destroy(l);

    return 0;
}

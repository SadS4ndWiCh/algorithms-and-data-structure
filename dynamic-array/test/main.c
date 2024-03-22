#include <stdio.h>

#include "../src/list.h"

int main() {
    List* dyn = newDyn(2);

    pushDyn(dyn, 2);
    pushDyn(dyn, 5);
    pushDyn(dyn, 10);

    printf("%d\n", popDyn(dyn));
    printf("%d\n", popDyn(dyn));
    printf("%d\n", popDyn(dyn));

    destroyDyn(dyn);

    return 0;
}

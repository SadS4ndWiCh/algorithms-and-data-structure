#include <stdio.h>

#include "../src/linkedlist.h"

int main() {
    LinkedList* l = newLinkedList();

    pushLinkedList(l, 10);
    pushLinkedList(l, 20);
    pushLinkedList(l, 30);

    Node* node = getLinkedList(l, 20);
    printf("%d\n", node->value);

    removeLinkedList(l, 30);
    removeLinkedList(l, 20);
    removeLinkedList(l, 10);

    if (l->head == NULL) {
        printf("head already deleted");
    } else {
        printf("%d\n", l->head->value);
    }


    destroyLinkedList(l);

    return 0;
}

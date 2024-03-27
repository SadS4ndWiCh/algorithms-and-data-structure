#include <stdio.h>

#include "../src/linkedlist.h"

int main() {
    LinkedList* l = LinkedList_new();

    LinkedList_push(l, 10);
    LinkedList_push(l, 20);
    LinkedList_push(l, 30);

    Node* node = LinkedList_get(l, 20);
    printf("%d\n", node->value);

    LinkedList_remove(l, 30);
    LinkedList_remove(l, 20);
    LinkedList_remove(l, 10);

    if (l->head == NULL) {
        printf("head already deleted");
    } else {
        printf("%d\n", l->head->value);
    }


    LinkedList_destroy(l);

    return 0;
}

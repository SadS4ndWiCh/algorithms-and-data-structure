#include <stdlib.h>

#include "linkedlist.h"

LinkedList* newLinkedList() {
    return (LinkedList*) malloc(sizeof(LinkedList));
}

void pushLinkedList(LinkedList* l, int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;

    if (l->head == NULL) {
        l->head = node;
    } else {
        l->tail->next = node;
        node->prev = l->tail;
    }

    l->tail = node;
}

Node* getLinkedList(LinkedList* l, int val) {
    Node* curr = l->head;

    while (curr != NULL && curr->value != val) {
        curr = curr->next;
    }

    return curr;
}

void removeLinkedList(LinkedList* l, int val) {
    Node* node = getLinkedList(l, val);

    if (node == NULL) {
        return;
    } else if (node == l->head && node == l->tail) {
        l->head = NULL;
        l->tail = NULL;
    } else if (node == l->tail) {
        l->tail = l->tail->prev;
    } else if (node == l->head) {
        l->head = l->head->next;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    free(node);
}

void destroyLinkedList(LinkedList* l) {
    Node* prev = NULL;
    Node* curr = l->tail;

    while (curr != NULL) {
        prev = curr->prev;

        curr->prev = NULL;
        free(curr);

        curr = prev;
    }

    free(l);
}

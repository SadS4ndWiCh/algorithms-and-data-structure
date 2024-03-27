#include <stdlib.h>

#include "linkedlist.h"

LinkedList* LinkedList_new() {
    return (LinkedList*) malloc(sizeof(LinkedList));
}

void LinkedList_push(LinkedList* l, int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    
    if (l->head == NULL) {
        l->head = node;
        l->tail = node;
        return;
    }

    l->tail->next = node;
    node->prev = l->tail;
    l->tail = node;

}

Node* LinkedList_get(LinkedList* l, int val) {
    Node* curr = l->head;

    while (curr != NULL && curr->value != val) {
        curr = curr->next;
    }

    return curr;
}

void LinkedList_remove(LinkedList* l, int val) {
    Node* node = LinkedList_get(l, val);

    if (node == NULL) {
        return;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    free(node);
}

void LinkedList_destroy(LinkedList* l) {
    Node* curr = l->head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;

        free(curr);

        curr = next;
    }

    free(l);
}

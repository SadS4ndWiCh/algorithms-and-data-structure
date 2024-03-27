#include <stdlib.h>

#include "binarytree.h"

BinaryTree* BinaryTree_new() {
    return (BinaryTree*) malloc(sizeof(BinaryTree));
}

void BinaryTree_push(BinaryTree* bt, int value) {
    Node** curr = &bt->root;

    while ((*curr) != NULL) {
        if (value < (*curr)->value) {
            curr = &(*curr)->left;
        } else if (value > (*curr)->value) {
            curr = &(*curr)->right;
        } else {
            return;
        }
    }


    *curr = (Node*) malloc(sizeof(Node));
    (*curr)->value = value;
}

Node* BinaryTree_get(BinaryTree* bt, int value) {
    Node* curr = bt->root;

    while (curr != NULL) {
        if (value < curr->value) {
            curr = curr->left;
        } else if (value > curr->value) {
            curr = curr->right;
        } else {
            return curr;
        }
    }

    return NULL;
}

Node* Node_lowest(Node* node) {
    if (node == NULL || node->left == NULL) {
        return node;
    }

    return Node_lowest(node->left);
}

void Node_remove(Node** node) {
    if (node == NULL) {
        return;
    }

    if ((*node)->left == NULL && (*node)->right == NULL) {
        free(*node);
        return;
    }

    if ((*node)->left != NULL && (*node)->right == NULL) {
        (*node)->value = (*node)->left->value;
        Node_remove(&(*node)->left);
        return;
    }

    if ((*node)->left == NULL && (*node)->right != NULL) {
        (*node)->value = (*node)->right->value;
        Node_remove(&(*node)->right);
        return;
    }

    Node* lowest = Node_lowest((*node)->right);
    (*node)->value = lowest->value;

    Node_remove(&lowest);
}

void BinaryTree_remove(BinaryTree* bt, int value) {
    Node* node = BinaryTree_get(bt, value);

    if (node == NULL) {
        return;
    }

    Node_remove(&node);
}


void Node_destroy(Node* node) {
    if (node == NULL) {
        return;
    }

    Node_destroy(node->left);
    Node_destroy(node->right);
    
    free(node);
}

void BinaryTree_destroy(BinaryTree* bt) {
    Node_destroy(bt->root);

    free(bt);
}

#include <stdio.h>

#include "../src/binarytree.h"

int main() {
    BinaryTree* bt = BinaryTree_new();

    BinaryTree_push(bt, 10);
    BinaryTree_push(bt, 15);
    BinaryTree_push(bt, 13);
    BinaryTree_push(bt, 14);
    BinaryTree_push(bt, 4);

    printf("%d\n", bt->root->value);

    BinaryTree_remove(bt, 10);

    printf("%d\n", bt->root->value);
    printf("%d\n", bt->root->right->value);
    printf("%d\n", bt->root->right->left->value);

    BinaryTree_destroy(bt);

    return 0;
}

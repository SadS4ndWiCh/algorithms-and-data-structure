typedef struct Node {
    struct Node* left;
    struct Node* right;
    int value;
} Node;

typedef struct BinaryTree {
    struct Node* root;
} BinaryTree;

BinaryTree* BinaryTree_new(void);
void BinaryTree_destroy(BinaryTree* bt);
void BinaryTree_push(BinaryTree* bt, int value);
Node* BinaryTree_get(BinaryTree* bt, int value);
void BinaryTree_remove(BinaryTree* bt, int value);
Node* Node_lowest(Node* node);
void Node_remove(Node** node);
void Node_destroy(Node* node);

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* LinkedList_new();
void LinkedList_destroy(LinkedList* l);
Node* LinkedList_get(LinkedList* l, int val);
void LinkedList_push(LinkedList* l, int val);
void LinkedList_remove(LinkedList* l, int val);

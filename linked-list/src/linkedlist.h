typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int value;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* LinkedList_new(void);
void LinkedList_destroy(LinkedList* l);
Node* LinkedList_get(LinkedList* l, int val);
void LinkedList_push(LinkedList* l, int val);
void LinkedList_remove(LinkedList* l, int val);

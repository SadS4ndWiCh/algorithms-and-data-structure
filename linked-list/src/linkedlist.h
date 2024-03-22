typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    struct Node* head;
    struct Node* tail;
} LinkedList;

LinkedList* newLinkedList();
void pushLinkedList(LinkedList* l, int val);
Node* getLinkedList(LinkedList* l, int val);
void removeLinkedList(LinkedList* l, int val);
void destroyLinkedList(LinkedList* l);

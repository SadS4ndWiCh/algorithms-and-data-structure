typedef struct {
    unsigned int cap;
    unsigned int length;
    int* elements;
} List;

List* List_new(unsigned int cap);
void List_destroy(List* l);
void List_push(List* l, int val);
int List_get(List* l, unsigned int idx);
int List_pop(List* l);
void List_insert(List* l);
void List_extend(List* l);

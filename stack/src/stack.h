typedef struct Stack {
    unsigned int cap;
    unsigned int length;
    int* elements;
} Stack;

Stack* Stack_new(unsigned int cap);
void Stack_push(Stack* stk, int val);
int Stack_pop(Stack* stk);
void Stack_destroy(Stack* stk);

typedef struct {
    unsigned int cap;
    unsigned int length;
    int* elements;
} List;

List* newDyn(unsigned int cap);
void destroyDyn(List* dyn);
void pushDyn(List* dyn, int val);
int getDyn(List* dyn, unsigned int idx);
int popDyn(List* dyn);
void insertDyn(List* dyn);
void extendDyn(List* dyn);

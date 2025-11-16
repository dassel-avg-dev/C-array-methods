
typedef struct node *Nodeptr;

typedef int dataItem;

typedef struct node
{
    int data;
    Nodeptr next;
} StackNode;

typedef struct
{
    int count;
    Nodeptr top;
} StackHead;

typedef StackHead *Stack;

void display(Stack s);

Stack createStack();

void push(Stack s, dataItem item);

void pop(Stack s);

int isEmpty(Stack s);

dataItem peek(Stack s);

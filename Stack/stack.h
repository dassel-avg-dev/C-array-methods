
typedef struct node *nodeptr;

typedef int dataItem;

typedef struct node
{
    int data;
    nodeptr next;
} StackNode;

typedef struct
{
    int count;
    nodeptr top;
} StackHead;

typedef StackHead *Stack;

void display(Stack s);

Stack createStack();

nodeptr createNode(dataItem item);

void push(Stack s, dataItem item);

void pop(Stack s);

int isEmpty(Stack s);

int isEqual(Stack s1, Stack s2);

Stack append(Stack s1, Stack s2);

dataItem peek(Stack s);

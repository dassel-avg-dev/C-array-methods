
typedef struct node* Nodeptr;

typedef int dataItem;

typedef struct node {
    dataItem data;
    Nodeptr next;
} QueueNode;

typedef struct {
    Nodeptr front;
    int count;
    Nodeptr rear;
} QueueHead;

typedef QueueHead* Queue;

Nodeptr createNode(dataItem item);

Queue createQueue();

void display(Queue q1);

void enqueue(Queue q1, dataItem item);

void dequeue(Queue q1);

int isEmpty(Queue q1);

dataItem peek(Queue q1);


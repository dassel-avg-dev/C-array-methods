
typedef struct node* nodeptr;

typedef struct node {
    int data;
    nodeptr next;
}Node;

typedef Node* List;

nodeptr createNode(int item);

List createList(int size);

List addAt(List head, int item, int pos);

List addFront(List head, int item);

List addEnd(List head, int item);

void display(List head);

int findItem(List head, int item);

int findMax(List head);

int findMin(List head);

int count(List head);

int computeSum(List head);




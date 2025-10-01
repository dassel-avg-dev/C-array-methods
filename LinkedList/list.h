
typedef struct node* nodeptr;

typedef struct node {
    int data;
    nodeptr next;
}Node;

typedef Node* List;

List createNode(int value);

List createList();

void display(List head);

int findItem(List head, int item);

int findMax(List head);

int findMin(List head);

int count(List head);

int computeSum(List head);


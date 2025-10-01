#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;

typedef struct node {
    int data;
    nodeptr next;
}Node;

typedef Node* List;

void display(List head);

int findItem(List head, int item);

int findMax(List head);

int findMin(List head);

int computeSum(List head);

List createList(int value);

int main() {
    //              manual allocate and assign
    // List head = (nodeptr)malloc(sizeof(Node)); // your root node
    // head->data = 1;

    // head->next = (nodeptr)malloc(sizeof(Node)); // 2nd node
    // head->next->data = 2;

    // head->next->next = (nodeptr)malloc(sizeof(Node));
    // head->next->next->data = 3;

    // head->next->next->next = (nodeptr)malloc(sizeof(Node));
    // head->next->next->next->data = 4;

    // head->next->next->next->next = NULL;

    List head = createList(1);
    head->next = createList(2);
    head->next->next = createList(3);
    head->next->next->next = createList(4);
    head->next->next->next->next = createList(5);
    head->next->next->next->next->next = createList(6);

    display(head);

    return 0;
}

int findItem(List head, int item) {
    nodeptr ptr = head;
    int found = 0;
    while(ptr != NULL) {
        if(ptr->data == item) {
            found = 1;
            break;
        }
        ptr = ptr->next;
    }
    return found;
}

int findMax(List head) {
    nodeptr ptr = head;
    int max = ptr->data;
    while(ptr != NULL) {
        if(ptr->data > max) {
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}

int findMin(List head) {
    nodeptr ptr = head;
    int min = ptr->data;
    while(ptr != NULL) {
        if(ptr->data < min) {
            min = ptr->data;
        }
        ptr = ptr->next;
    }
    return min;
}

int computeSum(List head) {
    nodeptr ptr = head;
    int sum = 0;
    while(ptr != NULL) {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

void display(List head) {
    nodeptr ptr = head;
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

List createList(int value) {
    List newNode = (nodeptr)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

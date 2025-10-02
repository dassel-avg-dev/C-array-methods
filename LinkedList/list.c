#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List createNode(int value) {
    List newNode = (nodeptr)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

List createList() {
    List head;
    int nodes;

    printf("Enter how many nodes should be in the list: ");
    scanf("%d", &nodes);

    printf("Enter node 1: ");
    head = (nodeptr)malloc(sizeof(Node));
    scanf("%d",&head->data);

    nodeptr ptr = head; // create node pointer that points to head
    for(int i=2; i<=nodes; i++) {
        printf("Enter node %d: ", i);
        ptr->next = (nodeptr)malloc(sizeof(Node)); // create and allocate new node
        scanf("%d",&ptr->next->data); // store input in the new node
        ptr = ptr->next; // move pointer 
    }

    return head;
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


int count(List head) {
    nodeptr ptr = head;
    int count=0;
    while(ptr!=NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
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





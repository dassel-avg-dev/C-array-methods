#include <stdio.h>
#include <stdlib.h>
#include "list.h"

nodeptr createNode(int item) {
    nodeptr newNode = (nodeptr)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Malloc failed!\n");
    }
    newNode->data = item;
    newNode->next = NULL;

    return newNode;
}

List createList(int size) {
    List head = (nodeptr)malloc(sizeof(Node));
    // node size greater than 1
    printf("Enter values\n");
    if(size != 1 && size > 1) {
        scanf("%d",&head->data);
        head->next = NULL;
        nodeptr ptr = head;
        for(int i=2; i<=size; i++) {
            scanf("%d",&ptr->next->data);
            ptr->next->next = NULL;
            ptr = ptr->next;
        }
    }
    else { // node size equal to 1
        scanf("%d",&head->data);
        head->next = NULL;
    }
    return head;
}

List addAt(List head, int item, int pos) {
    nodeptr temp = (nodeptr)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;
    if(pos!=1) {
        nodeptr ptr = head;
        int i=1;
        while(i < pos - 1) {
            ptr = ptr->next;
            i++;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
    return head;
}

List addFront(List head, int item) {
    nodeptr temp = (nodeptr)malloc(sizeof(Node));
    temp->data = item;
    temp->next = head;
    head = temp;
    return head;
}

List addEnd(List head, int item) {
    nodeptr temp = (nodeptr)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;
    nodeptr ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
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
    while(ptr->next != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}





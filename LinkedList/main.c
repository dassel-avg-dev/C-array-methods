#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

    //           Using a function
    // List head = createNode(1);
    // head->next = createNode(2);
    // head->next->next = createNode(3);
    // head->next->next->next = createNode(4);
    // head->next->next->next->next = createNode(5);
    // head->next->next->next->next->next = createNode(6);
    List head = createList();
    display(head);

    return 0;
}
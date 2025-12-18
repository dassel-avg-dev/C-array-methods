#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Nodeptr createNode(dataItem item) {
    Nodeptr temp = (Nodeptr)malloc(sizeof(QueueNode));
    temp->data = item;
    temp->next = NULL;
    return temp;
}

Queue createQueue() {
    Queue q1 = (Queue)malloc(sizeof(QueueNode));
    q1->front = q1->rear = NULL;
    q1->count = 0;
    return q1;
}

void display(Queue q1) {
    Nodeptr ptr = q1->front;

    printf("front\n");
    printf("|\n");

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("<- rear\n\n");

}

void enqueue(Queue q1, dataItem item) {
    Nodeptr temp = createNode(item);
    if(q1->count == 0) {
        q1->front = q1->rear = temp;
    }
    else {
        Nodeptr ptr = q1->rear;
        ptr->next = temp;
        q1->rear = temp;
    }
    (q1->count)++;
}

void dequeue(Queue q1) {
    if(q1->count > 0) {
        Nodeptr temp = q1->front;
        q1->front = temp->next;
        temp->next = NULL;
        free(temp);
        (q1->count)--;
    }
}

int isEmpty(Queue q1) {
    return q1->count == 0;
}

dataItem peek(Queue q1) {
    return q1->front->data;
}
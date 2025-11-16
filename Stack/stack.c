#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void display(Stack s)
{
    Nodeptr ptr = s->top;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

Stack createStack()
{
    Stack s = (Stack)malloc(sizeof(StackHead));
    s->count = 0;
    s->top = NULL;
    return s;
}

void push(Stack s, dataItem item)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(StackNode));
    temp->data = item;
    temp->next = s->top;
    s->top = temp;
    (s->count)++;
}

void pop(Stack s)
{
    Nodeptr temp = (Nodeptr)malloc(sizeof(StackNode));
    temp = s->top;
    s->top = temp->next;
    temp->next = NULL;
    (s->count)--;
    free(temp);
}

int isEmpty(Stack s)
{
    return (s->top == NULL) ? 1 : 0;
}

int peek(Stack s)
{
    return (s->top != NULL) ? s->top->data : -1;
}
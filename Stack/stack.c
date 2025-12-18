#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void display(Stack s)
{
    nodeptr ptr = s->top;
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

nodeptr createNode(dataItem item)
{
    nodeptr newNode = (nodeptr)malloc(sizeof(StackNode));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}

void push(Stack s, dataItem item)
{
    nodeptr temp = (nodeptr)malloc(sizeof(StackNode));
    temp->data = item;
    temp->next = s->top;
    s->top = temp;
    (s->count)++;
}

void pop(Stack s)
{
    if(s->count > 0) {
        nodeptr temp = s->top;
        s->top = temp->next;
        temp->next = NULL;
        free(temp);
        (s->count)--;
    }
}

int isEmpty(Stack s)
{
    return s->top == NULL;
}

// applies when both stack is sorted
int isEqual(Stack s1, Stack s2)
{
    int equal = 1;
    if (s1->count == s2->count)
    {
        nodeptr p1 = s1->top,
                p2 = s2->top;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data != p2->data)
            {
                equal = 0;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    else
    {
        equal = 0;
    }
    return equal;
}

Stack append(Stack s1, Stack s2)
{
    if (s1->top != NULL && s2->top != NULL)
    {
        nodeptr ptr = s1->top;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = s2->top;
        s1->count += s2->count;
        free(s2);
    }
    return s1;
}

int peek(Stack s)
{
    return (s->top != NULL) ? s->top->data : 0;
}
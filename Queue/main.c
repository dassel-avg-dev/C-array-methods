#include <stdio.h>
#include "queue.h"

int main() {
    Queue q1 = createQueue();

    enqueue(q1, 10);
    enqueue(q1, 20);
    enqueue(q1, 30);
    enqueue(q1, 40);
    enqueue(q1, 50);
    display(q1);
    dequeue(q1);
    display(q1);

    return 0;
}
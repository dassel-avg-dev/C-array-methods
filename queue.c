#include <stdio.h>
#include <stdbool.h>
#define SIZE 1000

int queue[SIZE];
int front = -1, rear = -1;

void enqueue();
void dequeue();
bool isEmpty();
bool isFull();
int peek();
void display();
void choices();

int main() {
    int input;
    int isRunning = 1;

    while (isRunning) {
        choices();
        scanf("%d", &input);
        switch(input) {
            case 0:
                isRunning = 0;
                break;
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf(isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 4:
                printf(isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 5:
                if (!isEmpty())
                    printf("The front element is: %d\n", peek());
                else
                    printf("Queue is empty!\n");
                break;
            case 6:
                display();
                break;
            default:
                printf("Invalid input, try again!\n");
                break;
        }
    }

    return 0;
}

void enqueue() {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    int item;
    printf("Enter the value of the item: ");
    scanf("%d", &item);
    if (front == -1) front = 0; // First insertion
    rear++;
    queue[rear] = item;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    front++;
    if (front > rear) { // Queue becomes empty
        front = rear = -1;
    }
}

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return (rear == SIZE - 1);
}

int peek() {
    return queue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i--) {
        printf("[ %d ] ", queue[i]);
    }
    printf("\n");
}

void choices() {
    printf("\n[0] Exit\n");
    printf("[1] Enqueue\n");
    printf("[2] Dequeue\n");
    printf("[3] Check if it's Empty\n");
    printf("[4] Check if it's Full\n");
    printf("[5] Peek\n");
    printf("[6] Display\n");
    printf("Enter your choice: ");
}

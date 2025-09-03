#include <stdio.h>

// Stack Methods 
void push();
void pop();
void peek();
void update();
void display();
void choices();

int stack[100], top = -1;

int main() {
    int isRunning = 1;
    int input;

    while (isRunning) 
    {
        choices();
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch(input)
        {
            case 0: printf("Exiting...\n"); isRunning = 0; break; 
            case 1: push(); display(); break;
            case 2: pop(); display(); break;
            case 3: peek(); display();break;
            case 4: update(); display(); break;
            default: printf("Invalid Input, Try Again!\n"); break;
        } 
    }
    
    return 0;
}

void push() {
    if (top >= 100) {
        printf("Stack is Full!");
    }

    int n ;
    printf("Enter a value to be inserted: ");
    scanf("%d", &n);

    top++;
    stack[top] = n;
}

void pop() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } 
    else {
        int item;
        item = stack[top];
        top--;
        printf("The poped item is %d\n", item);
    }
}

void peek() {
    if (top >= 0) {
        printf("The top element is %d\n", stack[top]);
    }
}

void update() {
    int item, position;
    printf("Enter the position to update: ");
    scanf("%d", &position);

    printf("Enter the item to insert: ");
    scanf("%d", &item);

    // checks if the position is less than the start position of the stack
    if (top - (position - 1) < 0) {
        printf("Underflow Condition!\n");
    }
    else {
        stack[top - (position - 1)] = item;
    }
}

void display() {
    if (top < 0) {
        printf("Cannot display empty stack!");
    }
    else {
        for (int i=top; i>=0; i--) {
            printf("[    %d   ]\n", stack[i]);
        }
    }
}

void choices() {
    printf("Stack Methods\n");
    printf("[0] Exit\n");
    printf("[1] Push\n");
    printf("[2] Pop\n");
    printf("[3] Peek\n");
    printf("[4] Update\n");
}
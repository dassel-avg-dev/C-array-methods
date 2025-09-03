#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Print the list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Insert at end
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Insert at beginning
void insertAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Insert at a given position (0-based index)
void insertAtPosition(Node** head, int value, int position) {
    if (position == 0) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Delete by value
void deleteByValue(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Delete from beginning
void deleteFromBeginning(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from end
void deleteFromEnd(Node** head) {
    if (*head == NULL) return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Search for a value
int search(Node* head, int value) {
    int position = 0;
    while (head != NULL) {
        if (head->value == value) return position;
        head = head->next;
        position++;
    }
    return -1;
}

// Free the entire list
void freeList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

// Main function to test
int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head); // 10 -> 20 -> 30 -> NULL

    insertAtBeginning(&head, 5);
    printList(head); // 5 -> 10 -> 20 -> 30 -> NULL

    insertAtPosition(&head, 15, 2);
    printList(head); // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    deleteByValue(&head, 10);
    printList(head); // 5 -> 15 -> 20 -> 30 -> NULL

    deleteFromBeginning(&head);
    printList(head); // 15 -> 20 -> 30 -> NULL

    deleteFromEnd(&head);
    printList(head); // 15 -> 20 -> NULL

    int index = search(head, 20);
    printf("Value 20 found at index: %d\n", index); // Should print 1

    freeList(&head);
    return 0;
}

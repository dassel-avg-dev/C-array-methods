#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode* ListNodeptr;

typedef struct ListNode {
    int val;
    ListNodeptr next;
} ListNode; 

int getListSize(ListNodeptr head) {
    ListNodeptr curr = head;
    int size = 0;
    while(curr != NULL) {
        size++;
        curr = curr->next;
    }
    return size;
}

ListNodeptr createList(int size) {
    ListNodeptr head = (ListNodeptr)malloc(sizeof(ListNode));
    printf("Enter values: ");
    scanf("%d",&head->val);
    head->next = NULL;
    if(size > 1) {
        ListNodeptr curr = head;
        for(int i=2; i<=size; i++) {
            curr->next = (ListNodeptr)malloc(sizeof(ListNode));
            scanf("%d",&curr->next->val);
            curr->next->next = NULL;
            curr = curr->next;
        }
    }
    return head;
}

ListNodeptr removeNodes(ListNodeptr head, int val) {
    // handle edge cases if the node to be removed is in the head
    while(head!=NULL && head->val == val) {
        ListNodeptr temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }

    if(head == NULL) {
        return NULL;
    }

    ListNodeptr prev = head;
    ListNodeptr curr = (head) ? head->next : NULL;

    while(curr != NULL) {
        if(curr->val == val) {
            prev->next = prev->next->next;
            curr = curr->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

ListNodeptr deleteMiddleNode(ListNodeptr head) {
    int size = getListSize(head);
    if(size % 2 == 0) {
        size--;
    }
    size /= 2;
    ListNodeptr curr = head;
    for(int i = 1; i < size; i++) {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
} 

void display(ListNodeptr head) {
    ListNodeptr curr = head;
    printf("\n");
    while(curr!=NULL) {
        printf("%d -> ",curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

void freeList(ListNodeptr head) {
    while(head!=NULL) {
        ListNodeptr temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    printf("\nSuccesfully freed all nodes");
}
int main() { 
    ListNodeptr head = createList(7);
    // 1, 2, 3, 4, 5, 6, 7
    display(head);
    head = deleteMiddleNode(head);
    display(head);
    freeList(head);

    return 0;
}
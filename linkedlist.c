#include <stdio.h>
#include <stdlib.h>

// Define a simple structure for a singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* p;
    struct Node* q;

    // Insert elements at the end of the linked list
    for (int i = 1; i <= 5; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newNode;
        }
    }

    // Print the linked list
    printf("Linked List: ");
    p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    // Delete an element from the middle of the linked list
    int elementToDelete = 3;
    p = head;
    q = NULL;

    while (p != NULL && p->data != elementToDelete) {
        q = p;
        p = p->next;
    }

    if (p != NULL) {
        if (q == NULL) {
            // If the element to be deleted is the head
            head = p->next;
        } else {
            q->next = p->next;
        }

        free(p); // Free the memory of the deleted node
    }

    // Print the linked list after deletion
    printf("Linked List after deleting %d: ", elementToDelete);
    p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    // Free the memory of the remaining nodes
    p = head;
    while (p != NULL) {
        struct Node* temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}

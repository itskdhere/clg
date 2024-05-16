#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed!!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key Not Found In The List\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
int main() {
    struct Node *head = NULL;
    int choice, data, key;
    while (1) {
        printf("\n\n1. Insert At Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Delete A Node\n");
        printf("4. Display The List\n");
        printf("5. Reverse Yhe List\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter Data to Insert At Beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter Data to Insert At End: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter Data To Delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;
        case 4:
            printf("List: ");
            display(head);
            break;
        case 5:
            printf("Reversed List: ");
            reverse(&head);
            display(head);
            reverse(&head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice!! Please enter a valid choice.\n");
        }
    }
    return 0;
}
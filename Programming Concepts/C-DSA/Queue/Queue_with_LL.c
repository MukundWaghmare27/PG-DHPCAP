#include <stdio.h>
#include <stdlib.h>

void insertq();
void deleteq();
void display();

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL; 

int main() {
    int choice, cont = 1;

    do {
        printf("1. Insert \n2. Delete \n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                insertq();
                break;
            case 2: 
                deleteq();
                break;
            case 3: 
                display();
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue? (1 for yes / 0 for no): ");
        scanf("%d", &cont);
    } while (cont == 1);

    return 0;
}

void insertq() {
    struct Node *temp = malloc(sizeof(struct Node));  
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &temp->data);  
    temp->next = NULL;

    if (front == NULL && rear == NULL) {  
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    printf("Element inserted\n");
}

void deleteq() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        temp = front;
        front = front->next;  
        if (front == NULL) {  
            rear = NULL;
        }
        printf("Deleted element: %d\n", temp->data);
        free(temp);  
    }
}

void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

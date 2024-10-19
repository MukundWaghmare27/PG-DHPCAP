#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* addAtbeg(struct Node *head) {
    struct Node *ptr;
    ptr = malloc(sizeof(struct Node)); 
    
    ptr->data = 5;    
    ptr->next = head;     

    return ptr;           
}

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    //printf("NULL\n");
}

void AddAtEnd(struct Node *head){
    struct Node *Last, *temp;
    Last = malloc(sizeof(struct Node));
    temp = malloc(sizeof(struct Node));

    Last -> data = 20;
    Last -> next = NULL;

    temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = Last;
}

int main() {
    struct Node *head;
    head = malloc(sizeof(struct Node));  

    head->data = 10;   
    head->next = NULL; 

    head = addAtbeg(head);
    AddAtEnd(head);

    printList(head);

    return 0;
}

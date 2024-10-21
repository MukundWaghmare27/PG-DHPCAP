#include <stdio.h>
#define MAX 5  

int stack[MAX]; 
int top = -1;   

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);


    printf("%d popped from the stack.\n", pop());
    printf("%d popped from the stack.\n", pop());
    printf("%d popped from the stack.\n", pop());
    printf("%d popped from the stack.\n", pop());
    printf("%d popped from the stack.\n", pop());
    pop();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Stack operations
void push(int stack[], int *top, int item) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = item;
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[(*top)--];
}

// Queue operations
void enqueue(int queue[], int *front, int *rear, int item) {
    if (*rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++(*rear)] = item;
}

int dequeue(int queue[], int *front, int *rear) {
    if (*front > *rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[(*front)++];
}

// Driver code
int main() {
    int stack[MAX_SIZE];
    int top = -1;

    int queue[MAX_SIZE];
    int front = 0, rear = -1;

    // Stack example
    push(stack, &top, 1);
    push(stack, &top, 2);
    push(stack, &top, 3);

    printf("Stack elements: ");
    while (top != -1) {
        printf("%d ", pop(stack, &top));
    }
    printf("\n");

    // Queue example
    enqueue(queue, &front, &rear, 1);
    enqueue(queue, &front, &rear, 2);
    enqueue(queue, &front, &rear, 3);

    printf("Queue elements: ");
    while (front <= rear) {
        printf("%d ", dequeue(queue, &front, &rear));
    }
    printf("\n");

    return 0;
}


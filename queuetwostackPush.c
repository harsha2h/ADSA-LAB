#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element
void push(Stack *s, int x) {
    if (!isFull(s)) {
        s->arr[++s->top] = x;
    }
}

// Pop element
int pop(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }

    return s->arr[s->top--];
}

// Queue using two stacks
typedef struct {
    Stack s1;
    Stack s2;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    init(&q->s1);
    init(&q->s2);
}

// Enqueue
void enqueue(Queue *q, int x) {

    // Move everything from s1 to s2
    while (!isEmpty(&q->s1)) {
        push(&q->s2, pop(&q->s1));
    }

    // Insert new element into s1
    push(&q->s1, x);

    // Move everything back to s1
    while (!isEmpty(&q->s2)) {
        push(&q->s1, pop(&q->s2));
    }

    printf("Enqueued %d\n", x);
}

// Dequeue
void dequeue(Queue *q) {

    if (isEmpty(&q->s1)) {
        printf("Queue is empty\n");
        return;
    }

    int x = pop(&q->s1);

    printf("Dequeued %d\n", x);
}

int main() {

    Queue q;
    initQueue(&q);

    char op[20];
    int val;

    while (scanf("%s", op) == 1) {

        if (strcmp(op, "ENQUEUE") == 0) {
            scanf("%d", &val);
            enqueue(&q, val);
        }

        else if (strcmp(op, "DEQUEUE") == 0) {
            dequeue(&q);
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Queue structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int count;
} Queue;

// Initialize queue
void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->count == 0;
}

// Check if queue is full
int isFull(Queue *q) {
    return q->count == MAX;
}

// Enqueue
void enqueue(Queue *q, int x) {

    if (isFull(q))
        return;

    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = x;
    q->count++;
}

// Dequeue
int dequeue(Queue *q) {

    if (isEmpty(q))
        return -1;

    int x = q->arr[q->front];

    q->front = (q->front + 1) % MAX;
    q->count--;

    return x;
}

// Stack using two queues
typedef struct {
    Queue q1;
    Queue q2;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    init(&s->q1);
    init(&s->q2);
}

// PUSH operation
void push(Stack *s, int x) {

    enqueue(&s->q1, x);

    printf("Pushed %d\n", x);
}

// POP operation
int pop(Stack *s) {

    if (isEmpty(&s->q1)) {
        printf("Stack empty\n");
        return -1;
    }

    // Move all elements except the last
    // from q1 to q2
    while (s->q1.count > 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // The last element is the stack TOP
    int x = dequeue(&s->q1);

    // Swap q1 and q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    printf("Popped %d\n", x);

    return x;
}

int main() {

    Stack s;
    initStack(&s);

    char op[20];
    int val;

    while (scanf("%s", op) == 1) {

        if (strcmp(op, "PUSH") == 0) {

            scanf("%d", &val);
            push(&s, val);
        }

        else if (strcmp(op, "POP") == 0) {

            pop(&s);
        }
    }

    return 0;
}
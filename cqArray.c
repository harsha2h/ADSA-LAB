#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct {
    int arr[MAX_SIZE];
    int front, rear, count;
} CircularQueue;

// Initialize the queue
void init(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if queue is full
int isFull(CircularQueue *q) {
    return q->count == MAX_SIZE;
}

// Check if queue is empty
int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

// Insert an element into the queue
void enqueue(CircularQueue *q, int x) {
    if (isFull(q)) {
        printf("Queue FULL\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = x;
    q->count++;

    printf("Enqueued %d\n", x);
}

// Remove an element from the queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue EMPTY\n");
        return -1;
    }

    int x = q->arr[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;

    printf("Dequeued %d\n", x);
    return x;
}

// Display the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue EMPTY\n");
        return;
    }

    printf("Queue: ");

    for (int i = 0; i < q->count; i++) {
        int idx = (q->front + i) % MAX_SIZE;
        printf("%d ", q->arr[idx]);
    }

    printf("\n");
}

int main() {
    CircularQueue q;
    init(&q);

    char op[10];
    int x;

    while (scanf("%s", op) != EOF) {

        if (strcmp(op, "ENQUEUE") == 0) {
            scanf("%d", &x);
            enqueue(&q, x);
        }

        else if (strcmp(op, "DEQUEUE") == 0) {
            dequeue(&q);
        }

        else if (strcmp(op, "DISPLAY") == 0) {
            display(&q);
        }
    }

    return 0;
}
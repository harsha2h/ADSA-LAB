#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} CircularQueue;

void init(CircularQueue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(CircularQueue *q) {
    return q->front == NULL;
}

void enqueue(CircularQueue *q, int x) {
    Node *n = (Node *)malloc(sizeof(Node));

    n->data = x;

    if (isEmpty(q)) {
        n->next = n;
        q->front = n;
        q->rear = n;
    } 
    else {
        n->next = q->front;
        q->rear->next = n;
        q->rear = n;
    }

    printf("Enqueued %d\n", x);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue EMPTY\n");
        return -1;
    }

    int x = q->front->data;

    if (q->front == q->rear) {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } 
    else {
        Node *t = q->front;

        q->front = q->front->next;
        q->rear->next = q->front;

        free(t);
    }

    printf("Dequeued %d\n", x);

    return x;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue EMPTY\n");
        return;
    }

    Node *t = q->front;

    printf("Queue: ");

    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != q->front);

    printf("\n");
}

int main() {
    CircularQueue q;
    init(&q);

    char op[20];
    int x;

    while (scanf("%s", op) == 1) {

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
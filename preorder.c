#include <stdio.h>

#define MAX_N 100

typedef struct {
    int data;
    int left;
    int right;
} Node;

typedef struct {
    int data[MAX_N];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    Node tree[MAX_N];

    printf("Enter data, left child index and right child index:\n");
    printf("Use -1 for no child.\n");

    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i);
        scanf("%d %d %d",
              &tree[i].data,
              &tree[i].left,
              &tree[i].right);
    }

    Stack s;
    s.top = -1;

    // Root node is 0
    push(&s, 0);

    printf("\nPreorder Traversal: ");

    while (!isEmpty(&s)) {
        int current = pop(&s);

        printf("%d ", tree[current].data);

        // Push right first
        if (tree[current].right != -1)
            push(&s, tree[current].right);

        // Push left second
        if (tree[current].left != -1)
            push(&s, tree[current].left);
    }

    printf("\n");

    return 0;
}
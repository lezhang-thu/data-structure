#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

struct Queue {
    int *data;
    int front, rear;
    int MaxSize;
};

struct Queue *createQueue(int MaxSize) {
    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->data = (int *)malloc(MaxSize * sizeof(int));
    // MOD World. (explains WHY zero?)
    Q->front = Q->rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool isFull(struct Queue *Q) { return (Q->rear + 1) % Q->MaxSize == Q->front; }

bool enQueue(struct Queue *Q, int x) {
    if (isFull(Q)) {
        printf("队列满 ");
        return false;
    } else {
        Q->rear = (Q->rear + 1) % Q->MaxSize;
        Q->data[Q->rear] = x;
        return true;
    }
}

bool isEmpty(struct Queue *Q) { return Q->front == Q->rear; }

int deQueue(struct Queue *Q) {
    if (isEmpty(Q)) {
        printf("队列空 ");
        return ERROR;
    } else {
        Q->front = (Q->front + 1) % Q->MaxSize;
        return Q->data[Q->front];
    }
}

int main(void) {
    struct Queue *q = createQueue(7);
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    printf("%d\n", deQueue(q));
    enQueue(q, 4);
    enQueue(q, 5);
    enQueue(q, 6);
    printf("%d\n", deQueue(q));
    enQueue(q, 7);
    enQueue(q, 8);
    printf("%d\n", enQueue(q, 9));
    printf("Jobs:\n");
    while (!isEmpty(q)) printf("%d ", deQueue(q));
    printf("\n");
    return 0;
}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

struct Stack {
    int *data;
    int top;
    int MaxSize;
};

struct Stack *createStack(int MaxSize) {
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->data = (int *)malloc(MaxSize * sizeof(int));
    s->top = -1;
    s->MaxSize = MaxSize;
    return s;
}

bool isFull(struct Stack *s) { return s->top == s->MaxSize - 1; }

bool push(struct Stack *s, int x) {
    if (isFull(s)) {
        printf("堆栈满");
        return false;
    } else {
        s->data[++(s->top)] = x;
        return true;
    }
}

bool isEmpty(struct Stack *s) { return s->top == -1; }

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("堆栈空");
        return ERROR; /* ERROR是int的特殊值，标志错误 */
    } else
        return s->data[(s->top)--];
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    struct Stack *s = createStack(10);
    int k;
    for (k = 0; k < 5; k++) push(s, a[k]);
    while (!isEmpty(s)) printf("%d ", pop(s));
    printf("\n");
}

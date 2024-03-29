#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

struct HNode {
    int *data;
    int size, capacity;
};

int deQueue(struct HNode *h) {
    int x = h->data[h->size];
    h->data[h->size] = h->data[1];
    h->data[1] = x;

    h->size--;
   
    int k = 1;
    for(; 2 * k <= h->size; ) {
        int child = 2 * k; 
        if (child + 1 <= h->size && h->data[child + 1] > h->data[child])
            child += 1;
        if (h->data[child] > x) {
            h->data[k] = h->data[child];
            k = child;
        }
        else break;
    }
    h->data[k] = x;
    return h->data[h->size + 1];
}

struct HNode *createHeap(int maxSize) {
    struct HNode *h = (struct HNode*)malloc(sizeof(struct HNode));
    h->data = (int*)malloc(sizeof(int) * (maxSize + 1));
    h->capacity = maxSize;
    h->size = 0;
    return h;
}


// MaxHeap
void enQueue(struct HNode *q, int x) {
    // q->data[++q->size] = x;
    q->size++;
    int k = q->size;
    for (; k >= 2 && q->data[k / 2] < x; k = k / 2) {
        q->data[k] = q->data[k / 2];
    }
    q->data[k] = x;
}








void printHeap(struct HNode *);
struct HNode *createHeap(int maxsize) {
    struct HNode *h = (struct HNode *)malloc(sizeof(struct HNode));
    h->data = (int *)malloc(sizeof(int) * maxsize);
    h->size = 0;
    h->capacity = maxsize;
    return h;
}

bool isFull(struct HNode *h) { return h->size == h->capacity; }
bool isEmpty(struct HNode *h) { return h->size == 0; }

bool insert(struct HNode *h, int x) {
    int i;
    if (isFull(h)) {
        printf("最大堆已满");
        return false;
    }
    i = ++h->size;
    for (; i >= 2 && h->data[i / 2] < x; i /= 2) h->data[i] = h->data[i / 2];
    h->data[i] = x;
    return true;
}

int deleteMax(
    struct HNode *h) { /* 从最大堆h中取出键值为最大的元素，并删除一个结点 */
    int parent, child;
    int maxItem, x;
    if (isEmpty(h)) {
        printf("最大堆已为空");
        return ERROR;
    }
    maxItem = h->data[1]; /* 取出根结点存放的最大值 */
    /* 用最大堆中最后一个元素从根结点开始向上过滤下层结点 */
    x = h->data[h->size--]; /* 注意当前堆的规模要减小 */
    for (parent = 1; parent * 2 <= h->size; parent = child) {
        child = parent * 2;
        if ((child != h->size) && (h->data[child] < h->data[child + 1]))
            child++; /* child指向左右子结点的较大者 */
        if (x >= h->data[child])
            break; /* 找到了合适位置 */
        else       /* 下滤x */
            h->data[parent] = h->data[child];
    }
    h->data[parent] = x;
    return maxItem;
}

void percDown(struct HNode *h,
              int p) { /* 下滤：将h中以h->data[p]为根的子堆调整为最大堆 */
    int parent, child;
    int x;
    x = h->data[p]; /* 取出根结点存放的值 */
    for (parent = p; parent * 2 <= h->size; parent = child) {
        child = parent * 2;
        if ((child != h->size) && (h->data[child] < h->data[child + 1]))
            child++; /* child指向左右子结点的较大者 */
        if (x >= h->data[child])
            break; /* 找到了合适位置 */
        else       /* 下滤x */
            h->data[parent] = h->data[child];
    }
    h->data[parent] = x;
}

void buildHeap(
    struct HNode *h) { /* 调整h->data[]中的元素，使满足最大堆的有序性  */
    /* 这里假设所有h->size个元素已经存在h->data[]中 */
    int i;
    /* 从最后一个结点的父节点开始，到根结点1 */
    for (i = h->size / 2; i > 0; i--) {
        percDown(h, i);
        printHeap(h);
    }
}

void printHeap(struct HNode *h) {
    int k;
    for (k = 1; k <= h->size; k++) printf("%d ", h->data[k]);
    printf("\n");
}

int main(void) {
    int a[] = {79, 66, 43, 83, 30, 87, 38, 55, 91, 72, 49, 9};
    int k;
    struct HNode *h = createHeap(20);
    for (k = 0; k < 12; k++) h->data[k + 1] = a[k];
    h->size = 12;
    buildHeap(h);
    // printHeap(h);
    printf("\n");
    while (!isEmpty(h)) printf("%d ", deleteMax(h));
    printf("\n");
    return 0;
}

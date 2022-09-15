//导入 stdbool.h 来使用布尔类型
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

struct ListNode {
    int val;
    struct ListNode *next;
};

int Length(struct ListNode *L) {
    struct ListNode *p;
    int cnt = 0; /* 初始化计数器 */

    p = L->next; /* p指向表的第0个结点 */
    while (p) {
        p = p->next;
        cnt++; /* 当前p指向的是第cnt个结点 */
    }

    return cnt;
}

int FindKth(struct ListNode *L, int K) {
    struct ListNode *p;
    int cnt = 0; /* 位序从0开始 */
    p = L->next; /* p指向L的第0个结点 */
    while (p && cnt < K) {
        p = p->next;
        cnt++;
    }
    if ((cnt == K) && p)
        return p->val; /* 找到第K个 */
    else
        return ERROR; /* 否则返回错误信息 */
}

struct ListNode *Find(struct ListNode *L, int X) {
    struct ListNode *p = L->next;
    /* p指向L的第0个结点 */
    while (p && p->val != X)
        p = p->next;
    return p;
}

bool Insert(struct ListNode *L, int X, int i) { /* 这里默认L有头结点 */
    struct ListNode *t, *pre;
    int cnt = -1;
    /* 查找位序为i-1的结点 */
    pre = L; /* pre指向表头 */
    while (pre && cnt < i - 1) {
        pre = pre->next;
        cnt++;
    }
    if (pre == NULL || cnt != i - 1) { /* 所找结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    } else { /* 找到了待插结点的前一个结点pre；若i为0，pre就指向表头 */
        /* 插入新结点 */
        t = (struct ListNode *)malloc(
            sizeof(struct ListNode)); /*申请、填装结点*/
        t->val = X;
        t->next = pre->next;
        pre->next = t;
        return true;
    }
}

bool Delete(struct ListNode *L, int i) { /* 这里默认L有头结点 */
    struct ListNode *t, *pre;
    int cnt = -1;
    /* 查找位序为i-1的结点 */
    pre = L; /* pre指向表头 */
    while (pre && cnt < i - 1) {
        pre = pre->next;
        cnt++;
    }
    if (pre == NULL || cnt != i - 1 || pre->next == NULL) {
        /* 所找结点或位序为i的结点不在L中 */
        printf("删除位置参数错误\n");
        return false;
    } else { /* 找到了待删结点的前一个结点pre */
        /* 将结点删除 */
        t = pre->next;
        pre->next = t->next;
        free(t);
        return true;
    }
}

void printOut(struct ListNode *L) {
    struct ListNode *p = L->next;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void create(struct ListNode *L, int X) {
    struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
    t->val = X;
    t->next = L->next;
    L->next = t;
}

int main(void) {
    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
    L->next = NULL;

    int a[] = {5, 10, 21, 35, 11};

    int k;

    for (k = 0; k < 5; k++)
        create(L, a[4 - k]);
    printOut(L);
    /*for (k = 0; k < 5; k++)
        Insert(L, a[k], k);*/
    /*printf("%d\n", Length(L));
    printOut(L);
    struct ListNode *t = Find(L, 35);
    printf("%d\n", t->next->val);
    Delete(L, 0);
    printOut(L);
    printf("%d\n", FindKth(L, 4));
    printf("%d\n", FindKth(L, 3));*/
}

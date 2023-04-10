#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

int deepestLeavesSum(struct TreeNode *root) {
    int sum = 0;
    struct TreeNode **queue =
        (struct TreeNode **)malloc(sizeof(struct TreeNode *) * (int)1e4);
    // range: (front, rear]
    int front, rear;
    front = rear = -1;
    queue[++rear] = root;
    while (front != rear) {
        sum = 0;
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct TreeNode *node = queue[++front];
            sum += node->val;
            if (node->left != NULL) {
                queue[++rear] = node->left;
            }
            if (node->right != NULL) {
                queue[++rear] = node->right;
            }
        }
    }
    free(queue);
    return sum;
}

void zigzag(struct TreeNode *root) {
    /* Your Code - START */
    /* Your Code - END */
}

struct TreeNode *insert(struct TreeNode *root, int x) {
    if (root == NULL) {
        struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        p->val = x;
        p->left = p->right = NULL;
        return p;
    }
    // root为非空树
    if (x < root->val)
        root->left = insert(root->left, x);
    else if (x > root->val)
        root->right = insert(root->right, x);
    else {
        printf("节点已存在！\n");
    }
    return root;
}

int main(void) {
    /* 构造树 - 开始 */
    struct TreeNode *root = NULL;
    int a[] = {7, 3, 15, 1, 6, 9, 20};
    int k;
    for (k = 0; k < 7; k++) root = insert(root, a[k]);
    /* 构造树 - 结束 */
    zigzag(root);
    return 0;
}

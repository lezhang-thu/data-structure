
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N (100 + 1)
struct TreeNode {
    char val;
    struct TreeNode *left, *right;
};

void inorder(struct TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    inorder(root->right);
    printf("%c", root->val);
}

void leaves(struct TreeNode *root) {
    if (root) {
        if (!root->left && !root->right) printf("%c ", root->val);
        leaves(root->left);
        leaves(root->right);
    }
}

void level_order_traverse2(struct TreeNode *root) {
    struct TreeNode **queue =
        (struct TreeNode **)malloc(sizeof(struct TreeNode *) * N);
    int front, rear;
    // (front, rear]
    front = rear = -1;
    queue[++rear] = root;

    // 当队列不为空时
    while (front != rear) {
        int n = rear - front;
        int k;
        for (k = 0; k < n; k++) {
            // 队头出队列
            struct TreeNode *x = queue[++front];
            printf("%c ", x->val);
            if (x->left != NULL) queue[++rear] = x->left;
            if (x->right != NULL) queue[++rear] = x->right;
        }
        printf("\n");
    }
    printf("\n");
}

void level_order_traverse(struct TreeNode *root) {
    struct TreeNode **queue =
        (struct TreeNode **)malloc(sizeof(struct TreeNode *) * N);
    // range: (front, rear]
    int front, rear;
    front = rear = -1;
    queue[++rear] = root;
    while (front != rear) {
        struct TreeNode *node = queue[++front];
        printf("%c ", node->val);
        if (node->left != NULL) {
            queue[++rear] = node->left;
        }
        if (node->right != NULL) {
            queue[++rear] = node->right;
        }
    }
    printf("\n");
}

struct TreeNode *buildTree(char *preorder, int preorderSize, char *inorder,
                           int inorderSize) {
    if (preorderSize == 0) return NULL;

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int k = 0;
    while (inorder[k] != root->val) k++;
    root->left = buildTree(preorder + 1, k, inorder, k);
    root->right = buildTree(preorder + k + 1, preorderSize - k - 1,
                            inorder + k + 1, preorderSize - k - 1);
    return root;
}

int main(void) {
    char *preorder = (char *)malloc(sizeof(char) * N),
         *inorder = (char *)malloc(sizeof(char) * N);
    int n;
    scanf("%d", &n);
    fflush(stdin);
    fgets(preorder, sizeof(char) * N, stdin);
    fgets(inorder, sizeof(char) * N, stdin);

    struct TreeNode *r = buildTree(preorder, n, inorder, n);
    level_order_traverse2(r);
}

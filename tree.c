#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

void leaves(struct TreeNode *root) {
    if (root) {
        if (!root->left && !root->right) printf("%d ", root->val);
        leaves(root->left);
        leaves(root->right);
    }
}

int getHeight(struct TreeNode *root) {
    if (root) {
        int hLeft = getHeight(root->left);
        int hRight = getHeight(root->right);
        return (hLeft > hRight ? hLeft : hRight) + 1;
    }
    return 0;
}

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

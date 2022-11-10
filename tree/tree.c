#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

void inorder(struct TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

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

void zigzag(struct TreeNode *root) {
    /* Your Code - START */
    /* Your Code - END */
}

struct TreeNode *find(struct TreeNode *root, int x) {
    while (root) {
        if (x > root->val)
            root = root->right;
        else if (x < root->val)
            root = root->left;
        else
            return root;
    }
    return NULL;
}

struct TreeNode *findMin(struct TreeNode *root) {
    if (root)
        while (root->left) root = root->left;
    return root;
}

struct TreeNode *insert(struct TreeNode *root, int x) {
    if (!root) {
        root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = x;
        root->left = root->right = NULL;
    } else {
        if (x < root->val)
            root->left = insert(root->left, x);
        else if (x > root->val)
            root->right = insert(root->right, x);
    }
    return root;
}

struct TreeNode *delete (struct TreeNode *root, int x) {
    struct TreeNode *t;
    if (!root)
        printf("要删除的元素未找到\n");
    else {
        if (x < root->val)
            root->left = delete (root->left, x);
        else if (x > root->val)
            root->right = delete (root->right, x);
        else {
            if (root->left && root->right) {
                t = findMin(root->right);
                root->val = t->val;
                root->right = delete (root->right, root->val);
            } else {
                t = root;
                if (!root->left)
                    root = root->right;
                else
                    root = root->left;
                free(t);
            }
        }
    }
    return root;
}

int main(void) {
    /* 构造树 - 开始 */
    struct TreeNode *root = NULL;
    int a[] = {7, 3, 15, 9, 20};
    int k;
    for (k = 0; k < 5; k++) root = insert(root, a[k]);
    /* 构造树 - 结束 */
    zigzag(root);
    return 0;
    /*struct TreeNode *root = NULL;
    int a[] = {30, 15, 41, 33, 50, 35};
    int k;
    for (k = 0; k < 6; k++) root = insert(root, a[k]);
    printf("%d\n", deepestLeavesSum(root));
    insert(root, 34);
    printf("%d\n", deepestLeavesSum(root));
    delete (root, 33);
    printf("%d\n", deepestLeavesSum(root));
    delete (root, 34);
    printf("%d\n", deepestLeavesSum(root));
    delete (root, 23);*/
}

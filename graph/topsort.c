#include <stdio.h>
#include <string.h>

void topsort(int adj_matrix[][8], int n) {
    int indegree[8];
    memset(indegree, 0, sizeof(int) * 8);

    int i, j;
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++)
            if (adj_matrix[i][j]) indegree[j]++;
    }

    int stack[8];
    int top = -1;

    for (i = 0; i < n; i++)
        if (!indegree[i]) stack[++top] = i;

    while (top > -1) {
        int v = stack[top--];
        printf("%d ", v + 1);
        int w;
        for (w = 0; w < n; w++)
            if (adj_matrix[v][w]) {
                indegree[w]--;
                if (!indegree[w]) stack[++top] = w;
            }
    }
    printf("\n");
}

int main(void) {
    int adj_matrix[8][8];
    memset(adj_matrix, 0, sizeof(int) * 8 * 8);

    int edges[][2] = {{1, 2}, {1, 3}, {2, 3}, {3, 8}, {3, 7},
                      {4, 5}, {5, 3}, {5, 6}, {6, 7}, {7, 8}};

    int k;
    for (k = 0; k < 10; k++) {
        int src = edges[k][0] - 1, dst = edges[k][1] - 1;
        adj_matrix[src][dst] = 1;
    }

    topsort(adj_matrix, 8);
}

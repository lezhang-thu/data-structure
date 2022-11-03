#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void DFS(int adj_matrix[][8], int v, bool visited[]) {
    visited[v] = true;
    printf("%c ", (char)(v + 'A'));
    int k;
    for (k = 0; k < 8; k++) {
        if (adj_matrix[v][k] != 0 && !visited[k]) {
            DFS(adj_matrix, k, visited);
        }
    }
}

int main(void) {
    int adj_matrix[8][8];
    memset(adj_matrix, 0, sizeof(int) * 8 * 8);

    char edges[][2] = {{'A', 'B'}, {'B', 'C'}, {'C', 'D'},
                       {'A', 'D'}, {'A', 'E'}, {'E', 'F'},
                       {'F', 'G'}, {'G', 'H'}, {'E', 'H'}};

    int k;
    for (k = 0; k < 9; k++) {
        int src = edges[k][0] - 'A', dst = edges[k][1] - 'A';
        adj_matrix[src][dst] = 1;
        adj_matrix[dst][src] = 1;
    }

    /*int j;
    for (k = 0; k < 8; k++) {
        for (j = 0; j < 8; j++) printf("%d ", adj_matrix[k][j]);
        printf("\n");
    }


    return 0;*/

    bool visited[8];
    memset(visited, 0, sizeof(bool) * 8);

    DFS(adj_matrix, 'E' - 'A', visited);
    printf("\n");
    return 0;
}

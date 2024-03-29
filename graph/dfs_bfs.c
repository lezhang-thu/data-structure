#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DFS(int adj_matrix[][8], int v, bool visited[]);
void BFS(int adj_matrix[][8], int s, bool visited[]);
/*void DFS(int adj_matrix[][8], int v, bool visited[]) {
    visited[v] = true;
    printf("%c ", (char)(v + 'A'));
    int k;
    for (k = 0; k < 8; k++) {
        if (adj_matrix[v][k] && !visited[k]) {
            DFS(adj_matrix, k, visited);
        }
    }
}*/

/*void BFS(int adj_matrix[][8], int s, bool visited[]) {
    int* queue = (int*)malloc(sizeof(int) * (8 + 1));
    int front = 0, rear = 0;
    visited[s] = true;
    printf("%c ", (char)(s + 'A'));
    queue[++rear] = s;

    while (front < rear) {
        int v, w;
        v = queue[++front];
        for (w = 0; w < 8; w++)
            if (adj_matrix[v][w] && !visited[w]) {
                visited[w] = true;
                printf("%c ", (char)(w + 'A'));
                queue[++rear] = w;
            }
    }
}*/

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

    //DFS(adj_matrix, 'E' - 'A', visited);
    BFS(adj_matrix, 'E' - 'A', visited);
    printf("\n");

    /*memset(visited, 0, sizeof(bool) * 8);
    BFS(adj_matrix, 'E' - 'A', visited);
    printf("\n");
    return 0;*/
}

void DFS(int adj_matrix[][8], int v, bool visited[]) {
    visited[v] = true;
    printf("%c ", (char)(v + 'A'));
    int w;
    for (w=0; w<8; w++) {
       if (adj_matrix[v][w] == 1 && !visited[w])
            DFS(adj_matrix, w, visited);

    }
}

void BFS(int adj_matrix[][8], int s, bool visited[]) {  
    int *queue = (int*)malloc(sizeof(int) * 8);
    int front, rear;
    front = rear = -1;
    queue[++rear] = s;
    visited[s] = true;
    int d = 0;

    while (front != rear) {
        int i; 
        int size = rear - front;
        printf("distance: %d\n", d);
        for (i=0; i<size; i++) {
            int u = queue[++front];
            printf("%c ", (char)(u + 'A'));

            int k;
            for (k=0; k<8; k++)
                if (adj_matrix[u][k] == 1 && !visited[k]) {
                    queue[++rear] = k;
                    visited[k] = true;
                }
        }
        d++;
        printf("\n");
    }
    printf("\n");

}


#include <stdio.h>
#include <stdlib.h>

#define INF 100

struct node {
  char x, y;
  int weight;
  struct node *next;
};

int char2idx(char *s, char c) {
  int k = 0;
  while (s[k] != c) {
    k++;
  }
  return k;
}

void output_ret(struct node *h) {
  while (h != NULL) {
    printf("%c %c %d\n", h->x, h->y, h->weight);
    h = h->next;
  }
}

void init_adjmatrix(int **adjmatrix, char *s, int n) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      adjmatrix[i][j] = INF;

  FILE *f = fopen("graph.txt", "r");
  char x, y;
  int weight;
  int m;
  int k;
  fscanf(f, "%d\n", &m);

  // exit(0);
  for (k = 0; k < m; k++) {
    fscanf(f, "%c %c %d\n", &x, &y, &weight);
    // printf("%c %c %d\n", x, y, weight);
    i = char2idx(s, x);
    j = char2idx(s, y);
    adjmatrix[i][j] = weight;
    adjmatrix[j][i] = weight;
  }
  fclose(f);
}

struct node *Prim(int **graph, int n, int src, char *idx2char) {
  int *dist = (int *)malloc(sizeof(int) * n);
  int *parent = (int *)malloc(sizeof(int) * n);
  int i, j, k;
  struct node *head = NULL, *tail = NULL;

  for (i = 0; i < n; i++) {
    dist[i] = INF;
    parent[i] = -1;
  }

  dist[src] = 0;

  int min_dist;
  for (i = 0; i < n; i++) {
    min_dist = INF;
    // get min dist
    k = -1;
    for (j = 0; j < n; j++)
      if (dist[j] != -INF && dist[j] < min_dist) {
        k = j;
        min_dist = dist[j];
      }
    // update dist, parent
    dist[k] = -INF;
    for (j = 0; j < n; j++)
      if (graph[k][j] < dist[j]) {
        parent[j] = k;
        dist[j] = graph[k][j];
      }
    // add edge to MST
    if (parent[k] != -1) {
      struct node *t = (struct node *)malloc(sizeof(struct node));
      t->x = idx2char[parent[k]];
      t->y = idx2char[k];
      t->weight = graph[parent[k]][k];
      t->next = NULL;
      if (head == NULL) {
        head = t;
        tail = t;
      } else {
        tail->next = t;
        tail = t;
      }
    }
  }
  return head;
}

void out_adjmatrix(int **adjmatrix, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%d\t", adjmatrix[i][j]);
    printf("\n");
  }
}

int main() {

  /*char c;
  c = getc(stdin);
  if (c != '-') {
    ungetc(c, stdin);
    int k;
    scanf("%d", &k);
    printf("%d\n", k);
  }
  exit(1);*/

  int n = 10;
  int **adjmatrix = (int **)malloc(sizeof(int *) * n);
  int i;
  for (i = 0; i < n; i++)
    adjmatrix[i] = (int *)malloc(sizeof(int) * n);

  char *s = "ZBDWLXHFYC";
  init_adjmatrix(adjmatrix, s, n);

  /*out_adjmatrix(adjmatrix, n);
  return 0;*/

  char *idx2char = (char *)malloc(sizeof(char) * n);
  for (i = 0; i < n; i++)
    idx2char[i] = s[i];

  struct node *prim_ret = Prim(adjmatrix, n, char2idx(s, 'Z'), idx2char);
  output_ret(prim_ret);
  return 0;
}

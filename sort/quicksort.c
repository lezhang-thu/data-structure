#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void array_out(int A[], int i, int j) {
    int k;
    for (k = i; k <= j; k++) printf("%d ", A[k]);
    printf("\n");
}

void swap(int* x, int* y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    int j;
    for (j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A + i, A + j);
        }
    }
    swap(A + i + 1, A + r);
    return i + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        printf("before:\n");
        array_out(A, p, r);

        int q = partition(A, p, r);

        printf("after:\n");
        array_out(A, p, r);

        printf("**********\n");
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main() {
    int A[] = {85, 12, 59, 36, 62, 43, 94, 7, 35, 52};
    quicksort(A, 0, 9);
    int k;
    // for (k = 0; k < 10; k++)
    //     printf("%d ", a[k]);
    // printf("\n");
    // array_out(A, 0, 9);
    return 0;
}

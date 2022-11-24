#include <stdio.h>

void output_array(int A[], int n) {
    int k;
    for (k = 0; k < n; k++) printf("%d ", A[k]);
    printf("\n");
}

void insertion_sort(int A[], int n) {
    int i, j;
    for (j = 1; j < n; j++) {
        int key = A[j];
        i = j - 1;
        while (i > -1 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;

        // debug
        printf("j = %d\n", j);
        output_array(A, n);
    }
}

int main(void) {
    int A[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    insertion_sort(A, n);
    return 0;
}

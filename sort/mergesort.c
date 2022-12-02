#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int B[], int left, int mid, int right) {
    // Merge subarrays A[left ... mid] and A[mid + 1 ... right]
    // Using assisting array B
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (A[i] <= A[j])
            B[k] = A[i++];
        else
            B[k] = A[j++];
        k++;
    }
    while (i <= mid) B[k++] = A[i++];
    while (j <= right) B[k++] = A[j++];
    for (i = left; i <= right; i++) A[i] = B[i];
}

void x_mergesort(int A[], int B[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        x_mergesort(A, B, left, mid);
        x_mergesort(A, B, mid + 1, right);
        merge(A, B, left, mid, right);
    }
}

int main() {
    int A[] = {2, 10, 7, 3, 6, 8, 1, 9, 4, 5};
    int *B = (int *)malloc(sizeof(int) * 10);
    int k;
    printf("before sort:\n");
    for (k = 0; k < 10; k++) printf("%d ", A[k]);
    printf("\n");
    printf("after sort:\n");
    x_mergesort(A, B, 0, 9);
    free(B);
    for (k = 0; k < 10; k++) printf("%d ", A[k]);
    printf("\n");
}

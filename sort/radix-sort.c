#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_sort(int a[], int b[], int c[], int n, int r) {
    memset(c, 0, sizeof(int) * 10);
    int j;
    for (j = 0; j < n; j++) c[a[j] / r % 10]++;
    int i;
    for (i = 1; i < 10; i++) c[i] += c[i - 1];
    for (j = n - 1; j >= 0; j--) {
        int d = a[j] / r % 10;
        // **c[d] - 1**
        b[c[d] - 1] = a[j];
        c[d]--;
    }
    for (j = 0; j < n; j++) a[j] = b[j];
}

int main(void) {
    int a[] = {329, 457, 657, 839, 436, 720, 355};
    int b[7];
    int c[10];
    int k, r = 1;
    for (k = 0; k < 3; k++) {
        counting_sort(a, b, c, 7, r);
        r *= 10;
    }
    for (k = 0; k < 7; k++) printf("%d ", a[k]);
    printf("\n");
    return 0;
}

#include <stdio.h>

int main() {
    int p, q;
    scanf("%d", &p);

    int A[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);
    int B[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    int i = 0, j = 0;

    while (i < p && j < q) {
        if (A[i] <= B[j]) {
            printf("%d ", A[i++]);
        } else {
            printf("%d ", B[j++]);
        }
    }

    while (i < p) {
        printf("%d ", A[i++]);
    }

    while (j < q) {
        printf("%d ", B[j++]);
    }

    return 0;
}
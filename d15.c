#include <stdio.h>

int main() {
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    int sum = 0;
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (i == j) {
                sum += val;
            }
        }
    }
    printf("Sum of primary diagonal = %d\n", sum);
    return 0;
}
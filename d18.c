#include <stdio.h>

int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;
    int rotated[n];
    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }
    printf("\n");
    return 0;
}
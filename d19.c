#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void closestToZeroPair(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    int l = 0, r = n - 1;
    int closestSum = __INT_MAX__;
    int pair1 = arr[l], pair2 = arr[r];

    while (l < r) {
        int currentSum = arr[l] + arr[r];

        if (abs(currentSum) < abs(closestSum)) {
            closestSum = currentSum;
            pair1 = arr[l];
            pair2 = arr[r];
        }

        if (currentSum < 0)
            l++;
        else
            r--;
    }

    printf("Pair with sum closest to zero: %d %d\n", pair1, pair2);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    closestToZeroPair(arr, n);

    return 0;
}
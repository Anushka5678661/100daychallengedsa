#include <stdio.h>

// Function to check if allocation is possible with given maxPages
int isPossible(int arr[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) {
            return 0; // single book exceeds limit
        }

        if (currentSum + arr[i] > maxPages) {
            studentsRequired++;
            currentSum = arr[i];

            if (studentsRequired > m) {
                return 0;
            }
        } else {
            currentSum += arr[i];
        }
    }
    return 1;
}

// Function to find minimum possible maximum pages
int allocateBooks(int arr[], int n, int m) {
    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxBook) {
            maxBook = arr[i];
        }
    }

    int low = maxBook, high = sum, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller maximum
        } else {
            low = mid + 1; // increase limit
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int answer = allocateBooks(arr, n, m);
    printf("%d\n", answer);

    return 0;
}

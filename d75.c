#include <stdio.h>
#include <stdlib.h>

// Structure to store prefix sum and its index
struct Prefix {
    int sum;
    int index;
};

// Function to find length of longest subarray with sum 0
int longestZeroSumSubarray(int arr[], int n) {
    int maxLen = 0;
    int sum = 0;

    // Array to store prefix sums and their first occurrence index
    struct Prefix prefix[n];
    int prefixCount = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;  // subarray from start to i
        }

        // Check if this sum was seen before
        int found = -1;
        for (int j = 0; j < prefixCount; j++) {
            if (prefix[j].sum == sum) {
                found = prefix[j].index;
                break;
            }
        }

        if (found != -1) {
            // If sum seen before, update maxLen
            int len = i - found;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // Store this sum with index
            prefix[prefixCount].sum = sum;
            prefix[prefixCount].index = i;
            prefixCount++;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestZeroSumSubarray(arr, n);
    printf("%d\n", result);

    return 0;
}

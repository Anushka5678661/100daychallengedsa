#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int offset = MAX;
    int freq[2*MAX] = {0};

    int prefixSum = 0;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            count++;
        }

        count += freq[prefixSum + offset];
        freq[prefixSum + offset]++;
    }

    printf("Count of subarrays with sum zero: %lld\n", count);

    return 0;
}
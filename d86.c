#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1) return n;  // Base cases

    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid <= n / mid) {  // Avoid overflow: mid*mid <= n
            ans = mid;        // mid is a candidate
            low = mid + 1;    // Search right half
        } else {
            high = mid - 1;   // Search left half
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));
    return 0;
}

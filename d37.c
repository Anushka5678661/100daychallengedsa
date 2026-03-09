#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[1000], size = 0;
    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            arr[size++] = x;
        } else if (strcmp(op, "delete") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int minIndex = 0;
                for (int j = 1; j < size; j++) {
                    if (arr[j] < arr[minIndex]) minIndex = j;
                }
                int deleted = arr[minIndex];
                for (int j = minIndex; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                printf("%d\n", deleted);
            }
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int minVal = arr[0];
                for (int j = 1; j < size; j++) {
                    if (arr[j] < minVal) minVal = arr[j];
                }
                printf("%d\n", minVal);
            }
        }
    }
    return 0;
}
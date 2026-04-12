#include <stdio.h>
#include <string.h>

#define EMPTY -1

// Global hash table
int table[1000];  // adjust max size if needed
int m;            // table size

// Insert function
void insert(int key) {
    int h = key % m;
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            table[pos] = key;
            return;
        }
    }
    // If table is full, insertion fails silently
}

// Search function
int search(int key) {
    int h = key % m;
    for (int i = 0; i < m; i++) {
        int pos = (h + i * i) % m;
        if (table[pos] == EMPTY) {
            return 0; // NOT FOUND
        }
        if (table[pos] == key) {
            return 1; // FOUND
        }
    }
    return 0; // NOT FOUND
}

int main() {
    int n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}

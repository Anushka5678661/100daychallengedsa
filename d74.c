#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store candidate name and vote count
typedef struct {
    char name[100];
    int count;
} Candidate;

// Function to compare two strings lexicographically
int isLexSmaller(char *a, char *b) {
    return strcmp(a, b) < 0;
}

int main() {
    int n;
    scanf("%d", &n);

    Candidate candidates[n];  // array to store candidates
    int uniqueCount = 0;      // number of unique candidates

    for (int i = 0; i < n; i++) {
        char vote[100];
        scanf("%s", vote);

        // Check if candidate already exists
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(candidates[j].name, vote) == 0) {
                candidates[j].count++;
                found = 1;
                break;
            }
        }

        // If not found, add new candidate
        if (!found) {
            strcpy(candidates[uniqueCount].name, vote);
            candidates[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    // Find candidate with maximum votes
    char winner[100];
    int maxVotes = -1;

    for (int i = 0; i < uniqueCount; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        } else if (candidates[i].count == maxVotes) {
            if (isLexSmaller(candidates[i].name, winner)) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}

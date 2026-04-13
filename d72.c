#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[256] = {0};  // frequency array for ASCII characters
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
        if (freq[(unsigned char)s[i]] == 2) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}

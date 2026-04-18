#include <stdio.h>
#include <string.h>

int main() {

    char words[6][20];
    int seen[6] = {0};
    int i, j, count, len;

    printf("Enter 6 words:\n");
    for (i = 0; i < 6; i++) {
        printf("Word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    printf("\n--- Word Frequency ---\n");
    for (i = 0; i < 6; i++) {

        if (seen[i] == 1)
            continue;

        count = 1;
        for (j = i + 1; j < 6; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
                seen[j] = 1;
            }
        }

        printf("Word: ");
        len = strlen(words[i]);
        for (j = 0; j < len; j++)
            printf("%c ", words[i][j]);

        printf("- appeared %d time(s)\n", count);
    }

    return 0;
}


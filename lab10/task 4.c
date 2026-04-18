#include <stdio.h>
#include <string.h>

int main() {

    char names[5][30];
    char search[30];
    int i, len, found = -1;

    printf("Enter 5 student names:\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d: ", i + 1);
        fgets(names[i], 30, stdin);
        len = strlen(names[i]);
        if (names[i][len - 1] == '\n')
            names[i][len - 1] = '\0';
    }

    printf("\n--- Class List ---\n");
    for (i = 0; i < 5; i++) {
        printf("%d. ", i + 1);
        fputs(names[i], stdout);
        printf("\n");
    }

    printf("\nEnter name to search: ");
    fgets(search, 30, stdin);
    len = strlen(search);
    if (search[len - 1] == '\n')
        search[len - 1] = '\0';

    for (i = 0; i < 5; i++) {
        if (strcmp(names[i], search) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1)
        printf("Found at position %d\n", found + 1);
    else
        printf("Student not found\n");

    return 0;
}


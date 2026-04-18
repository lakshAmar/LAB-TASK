#include <stdio.h>
#include <string.h>

int main() {

    char stored[20] = "Laksh";
    char input[20];
    int i;
    int success = 0;

    printf("=== Login System ===\n");

    for (i = 1; i <= 3; i++) {
        printf("Attempt %d - Enter password: ", i);
        scanf("%s", input);

        if (strlen(input) == 0) {
            printf("Password cannot be empty.\n");
            continue;
        }

        if (strcmp(stored, input) == 0) {
            printf("Login successful!\n");
            success = 1;
            break;
        }

        if (strcmp(input, stored) < 0)
            printf("Wrong password. Input is alphabetically before stored.\n");
        else
            printf("Wrong password. Input is alphabetically after stored.\n");

        if (i == 2) {
            if (strncmp(stored, input, 3) == 0)
                printf("Hint: First 3 characters match.\n");
            else
                printf("Hint: First 3 characters do not match.\n");
        }
    }

    if (success == 0)
        printf("Account locked. Too many failed attempts.\n");

    return 0;
}


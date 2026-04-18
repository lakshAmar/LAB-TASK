#include <stdio.h>
#include <string.h>

int main() {

    char email[50];
    char copy[50];
    char display[80] = "Email: ";
    char *at;
    char *dot;

    printf("Enter email address: ");
    scanf("%s", email);

    strcpy(copy, email);

    at = strchr(copy, '@');

    if (at == NULL) {
        printf("Error: Invalid email, no @ found.\n");
        return 0;
    }

    printf("Domain: %s\n", at + 1);

    dot = strstr(at, ".");
    if (dot == NULL) {
        printf("Error: Domain has no . separator.\n");
        return 0;
    }

    strcat(display, copy);
    printf("%s\n", display);

    return 0;
}


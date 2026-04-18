#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main() {

    char name[50];
    int len, i;
    int valid = 1;

    printf("Enter student name: ");
    fgets(name, 50, stdin);

    len = strlen(name);
    if (name[len - 1] == '\n') {
        name[len - 1] = '\0';
        len--;
    }

    if (len < 3 || len > 20)
        valid = 0;

    if (name[0] == ' ' || name[len - 1] == ' ')
        valid = 0;

    for (i = 0; i < len; i++) {
        if (isdigit(name[i]))
            valid = 0;
    }

    printf("Length: %d\n", len);

    if (valid == 1)
        printf("Valid Name\n");
    else
        printf("Invalid Name\n");

    return 0;
}


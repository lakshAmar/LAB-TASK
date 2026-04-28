#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *contactIDs;
    int *temp;

    contactIDs = (int *)malloc(3 * sizeof(int));

    if (contactIDs == NULL) {
        printf("Initial memory allocation failed.\n");
        return 0;
    }

    printf("Enter 3 contact IDs:\n");
    for (i = 0; i < 3; i++) {
        printf("Contact %d: ", i + 1);
        scanf("%d", &contactIDs[i]);
    }

    temp = (int *)realloc(contactIDs, 5 * sizeof(int));

    if (temp == NULL) {
        printf("Memory reallocation failed. Old contact list is still safe.\n");
        free(contactIDs);
        contactIDs = NULL;
        return 0;
    }

    contactIDs = temp;

    printf("\nEnter 2 more contact IDs:\n");
    for (i = 3; i < 5; i++) {
        printf("Contact %d: ", i + 1);
        scanf("%d", &contactIDs[i]);
    }

    printf("\n--- Updated Contact List ---\n");
    for (i = 0; i < 5; i++) {
        printf("Contact %d ID: %d\n", i + 1, contactIDs[i]);
    }

    free(contactIDs);
    contactIDs = NULL;

    return 0;
}

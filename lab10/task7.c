#include <stdio.h>

int main() {

    FILE *fptr;
    char product[30];
    int qty;
    char line[100];

    fptr = fopen("inventory.txt", "a");
    if (fptr == NULL) {
        printf("Error: Cannot open file.\n");
        return 0;
    }

    printf("Enter product name: ");
    scanf("%s", product);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    fprintf(fptr, "%s %d\n", product, qty);
    fclose(fptr);
    printf("Entry added.\n");

    fptr = fopen("inventory.txt", "r");
    if (fptr == NULL) {
        printf("Error: Cannot read file.\n");
        return 0;
    }

    printf("\n--- All Inventory Entries ---\n");
    while (fgets(line, 100, fptr) != NULL) {
        printf("%s", line);
    }
    fclose(fptr);

    return 0;
}


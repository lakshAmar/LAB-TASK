#include <stdio.h>

int main() {

    FILE *fptr;
    char name[30];
    int grade;
    int i;

    fptr = fopen("grades.txt", "w");
    if (fptr == NULL) {
        printf("Error: Cannot open file.\n");
        return 0;
    }

    printf("Enter 3 students details:\n");
    for (i = 0; i < 3; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%s", name);
        printf("Student %d grade: ", i + 1);
        scanf("%d", &grade);
        fprintf(fptr, "%s %d\n", name, grade);
    }
    fclose(fptr);
    printf("\nData written to grades.txt\n");

    fptr = fopen("grades.txt", "r");
    if (fptr == NULL) {
        printf("Error: Cannot reopen file.\n");
        return 0;
    }

    printf("\n--- Stored Records ---\n");
    while (fscanf(fptr, "%s %d", name, &grade) == 2) {
        printf("Name: %s | Grade: %d\n", name, grade);
    }
    fclose(fptr);

    return 0;
}


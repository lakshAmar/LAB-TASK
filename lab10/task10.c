#include <stdio.h>

int main() {

    FILE *fptr;
    char name[30];
    int s1, s2, s3;
    float avg;
    char status[10];
    char line[100];

    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter marks for 3 subjects: ");
    scanf("%d %d %d", &s1, &s2, &s3);

    avg = (s1 + s2 + s3) / 3.0;

    if (avg >= 50)
        sprintf(status, "Pass");
    else
        sprintf(status, "Fail");

    fptr = fopen("report.txt", "w+");
    if (fptr == NULL) {
        printf("Error: Cannot open file.\n");
        return 0;
    }

    fprintf(fptr, "===== Report Card =====\n");
    fprintf(fptr, "Name: %s\n", name);
    fprintf(fptr, "Subject 1: %d\n", s1);
    fprintf(fptr, "Subject 2: %d\n", s2);
    fprintf(fptr, "Subject 3: %d\n", s3);
    fprintf(fptr, "Average: %.2f\n", avg);
    fprintf(fptr, "Status: %s\n", status);
    fprintf(fptr, "=======================\n");

    rewind(fptr);

    printf("\n--- Reading Report Back ---\n");
    while (fgets(line, 100, fptr) != NULL) {
        printf("%s", line);
    }

    fclose(fptr);

    return 0;
}


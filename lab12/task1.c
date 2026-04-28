#include <stdio.h>
#include <stdlib.h>

int main() {
    int students, i;
    float *grades;

    printf("Enter number of students: ");
    scanf("%d", &students);

    if (students <= 0) {
        printf("Invalid number of students.\n");
        return 0;
    }

    grades = (float *)malloc(students * sizeof(float));

    if (grades == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    for (i = 0; i < students; i++) {
        printf("Enter grade of student %d: ", i + 1);
        scanf("%f", &grades[i]);
    }

    printf("\n--- Student Grades ---\n");
    for (i = 0; i < students; i++) {
        printf("Student %d: %.2f\n", i + 1, grades[i]);
    }

    free(grades);
    grades = NULL;

    return 0;
}

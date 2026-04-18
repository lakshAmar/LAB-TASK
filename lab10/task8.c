#include <stdio.h>

int main() {

    FILE *fptr;
    int score, sum = 0, val;
    int i, count = 0;
    float avg;

    fptr = fopen("survey.txt", "w");
    if (fptr == NULL) {
        printf("Error: Cannot open file.\n");
        return 0;
    }

    printf("Enter 5 scores (1-10):\n");
    for (i = 0; i < 5; i++) {
        printf("Score %d: ", i + 1);
        scanf("%d", &score);
        fprintf(fptr, "%d\n", score);
    }
    fclose(fptr);

    fptr = fopen("survey.txt", "r");
    if (fptr == NULL) {
        printf("Error: Cannot reopen file.\n");
        return 0;
    }

    while (fscanf(fptr, "%d", &val) == 1) {
        sum = sum + val;
        count++;
    }
    fclose(fptr);

    avg = (float)sum / count;

    printf("\n--- Survey Result ---\n");
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}

